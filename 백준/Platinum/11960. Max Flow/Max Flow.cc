// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int parent[50001][16];
vector<int> E[50001];
int depth[50001];
void dfs(int x) {
    for (int nx : E[x]) {
        if (nx == parent[x][0]) continue;
        parent[nx][0] = x;
        depth[nx] = depth[x] + 1;
        dfs(nx);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    for (int i = 0; i < 16; i++) {
        if (d & (1 << i)) a = parent[a][i];
    }
    if (a == b) return a;
    for (int i = 15; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];

}

int DP[50001];

void get(int x) {
    for (int nx : E[x]) {
        if (nx == parent[x][0]) continue;
        get(nx);
        DP[x] += DP[nx];
    }
}

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    dfs(1);

    for (int j = 1; j < 16; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    while (K--) {
        int a, b;
        cin >> a >> b;
        DP[a] += 1;
        DP[b] += 1;
        int l = lca(a, b);
        DP[l] -= 1;
        DP[parent[l][0]] -= 1;
    }

    get(1);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, DP[i]);
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