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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


ll adj[501][501];

void solve(int tc) {

    int N, M, E, K;
    cin >> N >> M >> E >> K;
    ll T1, T2;
    cin >> T1 >> T2;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][j] = INF;
        }
        adj[i][i] = 0;
    }

    while (M--) {
        ll c, t;
        cin >> c >> t;
        vector<int> v(c);
        for (int i = 0; i < c; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < c - 1; i++) {
            int a = v[i]; int b = v[i + 1];
            adj[a][b] = min(adj[a][b], (b - a) * t);
            adj[b][a] = adj[a][b];
        }
    }

    ll ans = INF;

    vector<ll> dist(N + 1, INF);
    dist[1] = 0;

    for (int k = 0; k <= K; k++) {

        vector<bool> visited(N + 1, false);

        for (int j = 0; j < N; j++) {
            int idx = 0;
            for (int i = 1; i <= N; i++) {
                if (visited[i]) continue;
                if (idx == 0 || dist[i] < dist[idx]) idx = i;
            }
            visited[idx] = true;

            for (int i = 1; i <= N; i++) {
                dist[i] = min(dist[i], dist[idx] + adj[idx][i]);
            }
        }

        ans = min(ans, dist[E]);

        vector<ll> nxdist(N + 1, INF);
        for (int i = 1; i <= N; i++) {
            if (i != 1) nxdist[i - 1] = min(nxdist[i - 1], dist[i] + T1 + T2 * k);
            if (i != N) nxdist[i + 1] = min(nxdist[i + 1], dist[i] + T1 + T2 * k);
        }

        dist = nxdist;
    }

    if (ans == INF) cout << -1;
    else cout << ans;






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