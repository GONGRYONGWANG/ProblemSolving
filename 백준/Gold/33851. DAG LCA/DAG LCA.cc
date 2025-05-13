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

int adj[2001][2001];
vector<int> E[2001];
int ind[2001];

void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][j] = inf;
        }
        adj[i][i] = 0;
    }

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[v].push_back(u);
        ind[u] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            for (int i = 1; i <= N; i++) adj[nx][i] = min(adj[nx][i], adj[x][i] + 1);
            ind[nx] -= 1;
            if (ind[nx] == 0) q.push(nx);
        }
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        int ret = inf;
        for (int i = 1; i <= N; i++) {
            ret = min(ret, max(adj[i][u], adj[i][v]));
        }
        if (ret == inf) cout << -1;
        else cout << ret;
        cout << endl;
    }





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