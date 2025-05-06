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


unordered_map<int, vector<int>> E[50001];
unordered_map<int, int> DP[500001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        E[u][x].push_back(v);
        E[v][x].push_back(u);
    }

    vector<int> ret(N + 1, inf);

    queue<pii> q;

    for (int x = 1; x <= M; x++) {
        for (int v : E[1][x]) {
            DP[v][x] = 1;
            ret[v] = 1;
            q.push({ v,x });
        }
    }

    while (!q.empty()) {
        int u = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int v : E[u][x - 1]) {
            if (DP[v].count(x - 1)) continue;
            DP[v][x - 1] = DP[u][x] + 1;
            ret[v] = min(ret[v], DP[v][x - 1]);
            q.push({ v,x - 1 });
        }
        for (int v : E[u][x + 1]) {
            if (DP[v].count(x + 1)) continue;
            DP[v][x + 1] = DP[u][x] + 1;
            ret[v] = min(ret[v], DP[v][x + 1]);
            q.push({ v,x + 1 });
        }
    }

    for (int i = 1; i <= N; i++) {
        if (ret[i] == inf) cout << -1;
        else cout << ret[i];
        cout << " ";
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