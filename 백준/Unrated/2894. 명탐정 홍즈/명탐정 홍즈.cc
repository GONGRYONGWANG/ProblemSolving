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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


vector<int> E[1001];
vector<int> rE[1001];
int cnt[1001];
int rcnt[1001];
bitset<1001> adj[1001];

void solve(int tc) {
    int D, M, N;
    cin >> D >> M >> N;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        assert(u != v);
        E[u].push_back(v);
        rE[v].push_back(u);
        cnt[u] += 1;
        rcnt[v] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= D; i++) {
        if (cnt[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        adj[x][x] = true;

        for (int p : rE[x]) {
            adj[p] |= adj[x];
            cnt[p] -= 1;
            if (cnt[p] == 0) q.push(p);
        }
    }

    for (int i = 1; i <= D; i++) {
        if (rcnt[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (rE[x].size() != 0) {
            bitset<1001> bs; bs.set();
            for (int p : rE[x]) {
                bs &= adj[p];
            }
            adj[x] |= bs;
        }

        for (int nx : E[x]) {
            rcnt[nx] -= 1;
            if (rcnt[nx] == 0) q.push(nx);
        }
    }

    vector<bool> visited(D + 1, false);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
        visited[x] = true;
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= D; i++) {
            if (adj[x][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 1; i <= D; i++) {
        if (visited[i]) cout << i << " ";
    }


    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}