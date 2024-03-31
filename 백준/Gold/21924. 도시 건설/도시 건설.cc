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

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

string debug = "output: ";

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

ll fastpow(ll x, ll n, ll mod = INF) {
    if (n == 0) return 1;
    if (n % 2) return x * fastpow(x, n - 1, mod) % mod;
    ll half = fastpow(x, n / 2, mod);
    return half * half % mod;
}


//////////////////////////////////////////////////////////////////////////////////////

vector<pii> E[100001];
bool visited[100001];

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

void solve() {

    int N, M;
    cin >> N >> M;


    ll total = 0;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({ b,c });
        E[b].push_back({ a,c });
        total += c;
    }

    ll ans = 0;

    pq<pii, vector<pii>, cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        int cur = q.top().first;
        int cost = q.top().second;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        ans += cost;
        for (int i = 0; i < E[cur].size(); i++) {
            int nx = E[cur][i].first;
            if (visited[nx]) continue;
            q.push({ nx, E[cur][i].second });
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << -1;
            return;
        }
    }

    cout << total - ans;



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

