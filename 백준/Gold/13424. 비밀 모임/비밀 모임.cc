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
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int>(N + 1, inf));
    for (int i = 1; i <= N; i++) {
        adj[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    for (int k = 1; k <= N; k++) {
        for (int u = 1; u <= N; u++) {
            for (int v = 1; v <= N; v++) {
                adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
            }
        }
    }
    int K;
    cin >> K;

    vector<int> ret(N + 1, 0);
    while (K--) {
        int x;
        cin >> x;
        for (int i = 1; i <= N; i++) {
            ret[i] += adj[i][x];
        }
    }

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        if (ret[i] < ret[ans]) ans = i;
    }
    cout << ans << endl;


}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }


        


    return 0;
}