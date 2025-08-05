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
#include<chrono>
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


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


int visited[3001][3001];

void solve(int tc) {
    
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> arr(K);

    for (int i = 0; i < K; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        arr[i] = { p + 1,x,y };
    }

    sort(arr.begin(), arr.end());

    int ans = 0;

    deque<pii> q;
    int a = arr.back()[1]; int b = arr.back()[2]; int c = arr.back()[0];
    arr.pop_back();
    q.push_back({ a,b });
    visited[a][b] = c;
    while (!q.empty()) {
        auto [x, y] = q.front();
        if (!arr.empty() && arr.back()[0] == visited[x][y]) {
            if (visited[arr.back()[1]][arr.back()[2]]) {
                arr.pop_back();
                continue;
            }
            q.push_front({ arr.back()[1], arr.back()[2] });
            visited[arr.back()[1]][arr.back()[2]] = arr.back()[0];
            arr.pop_back();
            continue;
        }
        q.pop_front();
        ans += 1;
        if (visited[x][y] == 1) continue;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M || visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] - 1;
            q.push_back({ nx,ny });
        }
    }

    cout << ans;


    


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}