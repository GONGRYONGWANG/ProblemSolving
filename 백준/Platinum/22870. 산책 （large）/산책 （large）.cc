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




//////////////////////////////////////////////////////////////////////////////////////


vector<pii> E[200001];
bool visited[200001];
struct cmp {
    bool operator()(pair<int, vector<int>> a, pair<int, vector<int>> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

void solve() {

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({ b,c });
        E[b].push_back({ a,c });
    }
    int s, e;
    cin >> s >> e;


    int ans = 0;

    pq<pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp> q;
    q.push({ 0,{s} });
    while (!q.empty()) {
        vector<int> v = q.top().second;
        int cur = v.back();
        int dist = q.top().first;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (cur == e) {
            ans += dist;
            fill(visited, visited + N + 1, false);
            for (int i = 1; i < v.size()-1; i++) {
                visited[v[i]] = true;
            }
            break;
        }

        for (int i = 0; i < E[cur].size(); i++) {
            int nx = E[cur][i].first;
            if (visited[nx]) continue;
            v.push_back(nx);
            q.push({ dist + E[cur][i].second, v });
            v.pop_back();
        }

    }

    q = {};

    q.push({ 0,{e} });
    while (!q.empty()) {
        vector<int> v = q.top().second;
        int cur = v.back();
        int dist = q.top().first;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (cur == s) {
            ans += dist;
            break;
        }

        for (int i = 0; i < E[cur].size(); i++) {
            int nx = E[cur][i].first;
            if (visited[nx]) continue;
            v.push_back(nx);
            q.push({ dist + E[cur][i].second, v });
            v.pop_back();
        }

    }
    cout << ans;
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
