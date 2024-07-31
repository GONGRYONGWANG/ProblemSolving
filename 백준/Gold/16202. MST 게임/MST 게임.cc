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


int parent[1001];
int findp(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

pii E[10001];
bool used[10001];
bool inG[10001];

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[2] > b[2];
    }
};

void solve() {

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    pq<vector<int>, vector<vector<int>>, cmp> q;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        E[i] = { u,v };
        q.push({ u,v,i });
    }

    pq<int, vector<int>, greater<int>> graph;

    int ans = 0;
    while (!q.empty()) {
        int u = q.top()[0];
        int v = q.top()[1];
        int w = q.top()[2];
        q.pop();
        u = findp(u);
        v = findp(v);
        if (u == v) continue;
        ans += w;
        parent[u] = v;
        used[w] = true;
        graph.push(w);
        inG[w] = true;
    }

    while (K--) {
        if (graph.size() != N - 1) {
            cout << 0 << " ";
            continue;
        }
        cout << ans << " ";
        ans -= graph.top();
        int u = E[graph.top()].first;
        int v = E[graph.top()].second;
        inG[graph.top()] = false;
        graph.pop();

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 1; i <= M; i++) {
            if (!inG[i]) continue;
            int a = E[i].first;
            int b = E[i].second;
            a = findp(a); b = findp(b);
            parent[a] = b;
        }

        for (int i = 1; i <= M; i++) {
            if (used[i]) continue;
            int a = E[i].first;
            int b = E[i].second;
            a = findp(a); b = findp(b);
            if (a != b) {
                used[i] = true;
                inG[i] = true;
                ans += i;
                graph.push(i);
                break;
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
