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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

const string debug = "output: ";

struct VectorHasher {
    size_t operator()(const vector<int>& V) const {
        size_t hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct PiiHasher {
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

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


//const ll Fsize = 1;
//ll F[Fsize];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x]; //
    return ret;
}

//ll modI[Fsize];  ll modIF[Fsize];
ll modinvfactorial(ll x) {
    ll ret = 1;
    //ret = modIF[x]; //
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    if (r == 0 || n == r) return 1;
    return factorial(n) * modinvfactorial(n - r) % mod * modinvfactorial(r) % mod;
}

ll ccw(pll a, pll b, pll c) {
    ll ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

bool intersect(pll A, pll B, pll C, pll D) { // 선분 교차 판정 A-B , C-D
    if (A > B) swap(A, B);
    if (C > D) swap(C, D);

    ll l1 = ccw(A, B, C) * ccw(A, B, D);
    ll l2 = ccw(C, D, A) * ccw(C, D, B);

    if (l1 == 0 && l2 == 0) {
        return A <= D && C <= B;
    }
    return l1 <= 0 && l2 <= 0;
}



//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////


bool bbbb;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    if (N == 0) { bbbb = false; return; }
    else bbbb = true;

    vector<vector<pii>> E(N + 1);
    for (int i = 0; i < M; i++) {
        char c;
        int u, v;
        cin >> c >> u >> v;
        int x;
        if (c == 'B') x = 1;
        else x = 0;
        E[u].push_back({ v,x });
        E[v].push_back({ u,x });
    }

    deque<pii> q;
    vector<bool> visited(N + 1, false);

    int mn = 0;
    q.push_back({ 1,0 });
    while (!q.empty()) {
        int cur = q.front().first;
        int color = q.front().second;
        q.pop_front();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (color) mn += 1;
        for (pii nx : E[cur]) {
            if (visited[nx.first]) continue;
            if (nx.second) q.push_back(nx);
            else q.push_front(nx);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << 0 << endl;
            return;
        }
        visited[i] = false;
    }

    int mx = 0;
    q.push_back({ 1,0 });
    while (!q.empty()) {
        int cur = q.front().first;
        int color = q.front().second;
        q.pop_front();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (color) mx += 1;
        for (pii nx : E[cur]) {
            if (visited[nx.first]) continue;
            if (!nx.second) q.push_back(nx);
            else q.push_front(nx);
        }
    }

    if (K >= mn && K <= mx) cout << 1;
    else cout << 0;
    cout << endl;

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T) {
        solve();
        if (!bbbb) break;
    }
    return 0;
}
