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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


struct VectorHasher { // unordered_set<vector<int>,VectorHasher>
    size_t operator()(const vector<int>& V) const {
        size_t hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};


const int MCMFSZ = 605; // The # of nodes.
struct MCMF {
    int n;
    int c[MCMFSZ][MCMFSZ] = { 0 }; // capacity
    int f[MCMFSZ][MCMFSZ] = { 0 }; // flow
    int d[MCMFSZ][MCMFSZ] = { 0 }; // dist
    vector<int> g[MCMFSZ]; // graph
    int source, sink;

    MCMF() {
        init(n);
    }

    MCMF(int n, int s, int t) {
        init(n);
        source = s; sink = t;
    }

    void init(int _n) {
        n = _n + 1;
        source = sink = -1;
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
    }

    void setSource(int s) {
        source = s;
    }

    void setSink(int t) {
        sink = t;
    }

    void addEdge(int s, int e, int cap, int dist) {
        g[s].push_back(e); c[s][e] = cap; d[s][e] = dist;
        g[e].push_back(s); c[e][s] = 0; d[e][s] = -dist;
    }

    int mcmf() {
        int cnt = 0;
        int minCost = 0;
        int prv[MCMFSZ], dist[MCMFSZ];
        bool inque[MCMFSZ] = { 0 };
        while (1) {
            memset(prv, -1, sizeof prv); memset(dist, inf, sizeof dist); memset(inque, 0, sizeof inque);
            queue<int> q;
            dist[source] = 0;
            inque[source] = 1;
            q.push(source);

            while (q.size()) {
                int now = q.front(); q.pop(); inque[now] = 0;
                for (auto nxt : g[now]) {
                    if (c[now][nxt] - f[now][nxt] > 0 && dist[nxt] > dist[now] + d[now][nxt]) {
                        dist[nxt] = dist[now] + d[now][nxt];
                        prv[nxt] = now;
                        if (!inque[nxt]) {
                            q.push(nxt);
                            inque[nxt] = 1;
                        }
                    }
                }
            }
            if (prv[sink] == -1) break;
            int flow = inf; // Adjust maximum flow for long long
            for (int i = sink; i != source; i = prv[i]) {
                flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
            }
            for (int i = sink; i != source; i = prv[i]) {
                minCost += flow * d[prv[i]][i];
                f[prv[i]][i] += flow;
                f[i][prv[i]] -= flow;
            }
            cnt++;
        }
        //cout << cnt << "\n";
        return minCost;
    }
}; //출저: justicehui.github.io


ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll xgcd(ll a, ll b) {
    ll r1 = a; ll r2 = b;
    ll s1 = 1; ll s2 = 0;
    ll t1 = 0; ll t2 = 1;
    while (1) {
        ll q = r1 / r2;
        ll r = r1 - q * r2;
        ll s = s1 - q * s2;
        ll t = t1 - q * t2;
        if (r == 0) return s2;
        r1 = r2; r2 = r;
        s1 = s2; s2 = s;
        t1 = t2; t2 = t;
    }
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

ll modinv(ll x, ll mod) { // mod is primenum
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


//int dx[4] = { 1,0,-1,0 }; // DRUL
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

int tree[2000000];
int lazy[2000000];
int arr[500001];
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void lazyProp(int node, int start, int end) {
    if ((end - start + 1) % 2) {
        tree[node] ^= lazy[node];
    }
    if (start != end) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
    return;
}

void update(int node, int start, int end, int left, int right, int k) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = k;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, k);
    update(node * 2 + 1, mid + 1, end, left, right, k);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) ^ get(node * 2 + 1, mid + 1, end, left, right);
}


void solve() {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, 1, N);
    int M;
    cin >> M;
    while (M--) {
        int t, l, r;
        cin >> t >> l >> r;
        l += 1; r += 1;
        if (t == 1) {
            int k;
            cin >> k;
            update(1, 1, N, l, r, k);
        }
        else {
            cout << get(1, 1, N, l, r) << endl;
        }
    }




}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

