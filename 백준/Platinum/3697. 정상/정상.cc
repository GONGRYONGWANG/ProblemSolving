// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int H[500][500];
pii parent[500][500];
pii findp(pii p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}

void solve(int tc) {

    int N, M, d;
    cin >> N >> M >> d;

    vector<vector<int>> arr;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> H[i][j];
            arr.push_back( { H[i][j],i,j });
            parent[i][j] = { -1,-1 };
        }
    }

    sort(arr.rbegin(), arr.rend());

    int idx = 0;

    int ans = 0;
    for (int i = 0; i < N * M; i++) {
        while (idx != N * M && arr[idx][0] > arr[i][0] - d) {
            int x = arr[idx][1]; int y = arr[idx][2];
            parent[x][y] = { x,y };
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (parent[nx][ny].first == -1) continue;
                pii p1 = findp({ nx,ny });
                pii p2 = findp({ x,y });
                if (H[p1.first][p1.second] < H[p2.first][p2.second]) swap(p1, p2);
                parent[p2.first][p2.second] = p1;
            }
            idx += 1;
        }

        int x = arr[i][1]; int y = arr[i][2];
        pii p = findp({ x,y });
        if (H[p.first][p.second] == arr[i][0]) ans += 1;

    }

    cout << ans << endl;




}
    


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}