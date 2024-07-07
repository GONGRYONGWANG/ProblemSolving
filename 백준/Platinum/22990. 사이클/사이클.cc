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
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
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

const int sz = 403;
int capacity[sz][sz];
int flow[sz][sz];
ll cost[sz][sz];
vector<int> E[sz];

int parent[sz];
ll d[sz];
bool inq[sz];


void solve() {
    int N, M;
    cin >> N >> M;
    int src = sz - 1;
    int sink = sz - 2;
    for (int i = 1; i <= N; i++) {
        E[src].push_back(i);
        E[i].push_back(src);
        capacity[src][i] = 1;
    }

    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        v += 200;
        E[u].push_back(v);
        E[v].push_back(u);
        capacity[u][v] = 1;
        cost[u][v] = w;
        cost[v][u] = -w;
    }
    
    for (int i = 201; i <= 200 + N; i++) {
        E[i].push_back(sink);
        E[sink].push_back(i);
        capacity[i][sink] = 1;
    }

    int match = 0;
    ll ans = 0;

    while (1) {
        fill(d, d + sz, INF);
        fill(parent, parent + sz, 0);
        fill(inq, inq + sz, false);
        d[src] = 0;
        parent[src] = src;
        inq[src] = true;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            inq[cur] = false;
            for (int nx : E[cur]) {
                if (capacity[cur][nx] - flow[cur][nx] <= 0 || d[nx] <= d[cur] + cost[cur][nx]) continue;
                d[nx] = d[cur] + cost[cur][nx];
                parent[nx] = cur;
                if (!inq[nx]) {
                    q.push(nx);
                    inq[nx] = true;
                }
            }
        }
        if (!parent[sink]) break;
        int minflow = inf;
        for (int i = sink; i != src; i = parent[i]) {
            minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for (int i = sink; i != src; i = parent[i]) {
            ans += cost[parent[i]][i] * minflow;
            flow[parent[i]][i] += minflow;
            flow[i][parent[i]] -= minflow;
        }
        match += minflow;
    }

    if (match != N) {
        cout << 0;
        return;
    }
    cout << 1 << endl;
    cout << ans << endl;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (flow[i][j + 200]) {
                cout << i << " " << j << endl;
            }
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
