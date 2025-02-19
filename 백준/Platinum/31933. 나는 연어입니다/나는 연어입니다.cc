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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

vector<pair<int, pii>> E[5001];


void solve(int tc) {

    int N, M;
    cin >> N >> M;

    map<int, int> m;
    m[1] = 0;
    while (M--) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        E[u].push_back({ v,{l,r} });
        E[v].push_back({ u,{l,r} });
        m[l] = 0; m[r + 1] = 0;
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        prev(m.upper_bound(x))->second += 1;
    }

    int ans = 0;

    for (auto it = m.begin(); it != m.end(); it++) {
        int x = it->first;
        vector<bool> visited(N + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (pair<int, pii> e : E[cur]) {
                int nx = e.first;
                if (visited[nx]) continue;
                auto [l, r] = e.second;
                if (x<l || x>r) continue;
                q.push(nx);
                visited[nx] = true;
            }
        }
        if (visited[N]) ans += it->second;
    }
    
    cout << ans;


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