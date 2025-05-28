// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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

vector<pll> E[300001];
ll DP[300001];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    ll N, M, K;
    cin >> N >> M >> K;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    vector<int> v;

    pq<pll, vector<pll>, cmp> q;
    q.push({ 1,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (DP[x]) continue;
        DP[x] = d;
        v.push_back(x);
        for (pll& e : E[x]) {
            if (DP[e.first]) continue;
            q.push({ e.first,e.second + d });
        }
    }

    for (int i = 1; i <= N; i++) DP[i] -= 1;

    vector<bool> visited(N + 1, false);

    ll ans = 0;

    ll cnt = 0;
    ll total = 0;
    deque<ll> dq;


    for (int x : v) {
        while (!dq.empty() && DP[x] - dq.front() > K + 1) {
            cnt -= 1;
            total -= dq.front();
            dq.pop_front();
        }
        ans += (K + 1) * cnt - (DP[x] * cnt - total);
        for (pll& e : E[x]) {
            if (!visited[e.first]) continue;
            ans -= max(0ll, K + 1 - (DP[x] - DP[e.first]));
        }

        total += DP[x];
        cnt += 1;
        dq.push_back(DP[x]);
        visited[x] = true;
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