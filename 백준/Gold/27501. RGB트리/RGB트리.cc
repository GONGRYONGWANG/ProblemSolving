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
    int operator()(const vector<int>& V) const {
        int hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
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


// F[];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

int ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

int dx[4] = { 0,1,0,-1};
int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////



vector<int> E[500001];
int arr[500001][3];

int parent[500001];
int DP[500001][3];
int dp(int cur, int col) {
    if (DP[cur][col]) return DP[cur][col];
    DP[cur][col] = arr[cur][col];
    for (int nx : E[cur]) {
        if (nx == parent[cur]) continue;
        DP[cur][col] += max(dp(nx, (col + 1) % 3), dp(nx, (col + 2) % 3));
    }
    return DP[cur][col];
}

int ansv[500001];
void dfs(int cur, int col) {
    ansv[cur] = col;
    for (int nx : E[cur]) {
        if (nx == parent[cur]) continue;
        if (dp(nx, (col + 1) % 3) > dp(nx, (col + 2) % 3)) {
            dfs(nx, (col + 1) % 3);
        }
        else {
            dfs(nx, (col + 2) % 3);
        }
    }
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nx : E[cur]) {
            if (nx == parent[cur]) continue;
            parent[nx] = cur;
            q.push(nx);
        }
    }

    int ans = max(max(dp(1, 0), dp(1, 1)), dp(1, 2));
    cout << ans << endl;

    if (ans == dp(1, 0)) {
        dfs(1, 0);
    }
    else if (ans == dp(1, 1)) {
        dfs(1, 1);
    }
    else {
        dfs(1, 2);
    }

    for (int i = 1; i <= N; i++) {
        if (ansv[i] == 0) cout << "R";
        else if (ansv[i] == 1) cout << "G";
        else cout << "B";
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
