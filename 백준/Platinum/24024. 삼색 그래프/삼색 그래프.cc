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
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


ll N, M, X;
vector<vector<ll>> E[200001];
struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

ll get(ll a) {
    ll b = X - a;
    vector<bool> visited(N + 1, false);
    pq<pll, vector<pll>, cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        int x = q.top().first;
        ll d = q.top().second;
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        if (x == N) return d;
        for (vector<ll>& e : E[x]) {
            int nx = e[0]; ll w = e[1]; int p = e[2];
            if (visited[nx]) continue;
            if (p == 1) w += a;
            else if (p == 2) w += b;
            ll nd  = d + w;
            q.push({ nx,nd });
        }
    }

}


void solve(int tc) {

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        ll u, v, w, p;
        cin >> u >> v >> w >> p;
        E[u].push_back({ v,w,p });
        E[v].push_back({ u,w,p });
    }

    ll l = 0, r = X;
    while (l + 2 < r) {
        ll m1 = (l * 2 + r) / 3;
        ll m2 = (l + r * 2) / 3;
        if (get(m1) <= get(m2)) l = m1;
        else r = m2;
    }

    ll ans = 0;
    for (ll i = l; i <= r; i++) {
        ans = max(ans, get(i));
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