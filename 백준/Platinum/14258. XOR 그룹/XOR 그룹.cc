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
#define INF ll(4e18)
const int inf = 1e9 + 7;
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

pii parent[1001][1001];
ll val[1001][1001];
pii findp(pii p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}

ll ret = 0;

void mer(pii p1, pii p2) {
    p1 = findp(p1); p2 = findp(p2);
    if (p1.first == 0 || p2.first == 0 || p1 == p2) return;
    ret -= val[p1.first][p1.second] + val[p2.first][p2.second];
    val[p1.first][p1.second] ^= val[p2.first][p2.second];
    ret += val[p1.first][p1.second];
    parent[p2.first][p2.second] = p1;
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> arr;

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            parent[i][j] = { 0,0 };
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int w;
            cin >> w;
            arr.push_back({ w,i,j });
        }
    }

    sort(arr.rbegin(), arr.rend());

    ll ans = 0;

    for (auto [w, x, y] : arr) {
        parent[x][y] = { x,y };
        val[x][y] = w;
        ret += w;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            mer({ x,y }, { nx,ny });
        }
        ans = max(ans, ret);
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