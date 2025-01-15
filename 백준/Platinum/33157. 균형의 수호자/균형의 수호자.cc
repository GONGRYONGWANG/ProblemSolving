// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/gcctemplate_for_pbds&rope
#include<bits/stdc++.h>
#include<ext/rope>
/*
string s;
s.c_str() -> 스트링을 char arr로
rope<char> rp(s.c_str());
rp.insert(idx, s.c_str());
rp.insert(idx, some_char);'
cout<<rp.substr(idx, length);
*/
typedef __int128 ll;
using namespace std;
using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") //SIMD



#define pq priority_queue
#define endl "\n"

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

const string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return powmod(x, mod - 2, mod);
}

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

ifstream fin; ofstream fout;
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };


string deb = "debug: ";

vector<pll> E[200001];
pll sz[200001];

void dfs(int x, int p) {
    sz[x] = { 1,0 };
    for (pll& e : E[x]) {
        int nx = e.first;
        if (nx == p) continue;
        dfs(nx, x);
        sz[x].first += sz[nx].first;
        sz[x].second += sz[nx].second + e.second * sz[nx].first;
    }
}

ll N;

pair<ll,int> get(int x, int p, ll sqtotal, ll total) {
    pair<ll,int>  ret = { sqtotal * N - total * total, x };
    for (pll& e : E[x]) {
        int nx = e.first;
        if (nx == p) continue;
        ll w = e.second;
        ll nxtotal = total + w * (N - 2 * sz[nx].first);
        ll nxsqtotal = sqtotal + 2 * (total - 2 * (sz[nx].second + w * sz[nx].first)) * w + w * w * N;
        pair<ll,int>  g = get(nx, x, nxsqtotal, nxtotal);
        if (g.first < ret.first) ret = g;
        else if (g.first == ret.first) ret.second = min(ret.second, g.second);
    }
    return ret;
}



void solve() {

    int n;
    cin>>n;
    N= n;
    for (int i = 0; i < N - 1; i++) {
        int U,V,W;
        cin>>U>>V>>W;
        __int128 u, v, w;
        u=U; v=V; w=W;
        E[U].push_back({ v,w });
        E[V].push_back({ u,w });
    }

    dfs(1, -1);

    ll sqtotal = 0;
    ll total = 0;
    queue<pll> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        ll x = q.front().first;
        ll d = q.front().second;
        q.pop();
        sqtotal += d * d;
        total += d;
        for (pll& e : E[x]) {
            int nx = e.first;
            if (sz[nx].first > sz[x].first) continue;
            q.push({ nx,d + e.second });
        }
    }

    cout << get(1, -1, sqtotal, total).second;



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    //fin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
