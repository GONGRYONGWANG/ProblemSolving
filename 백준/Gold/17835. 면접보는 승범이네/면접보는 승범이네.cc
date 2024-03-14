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

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
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


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}
*/

//////////////////////////////////////////////////////////////////////////////////////

vector<pll> E[100001];
bool visited[100001];

struct cmp {
    bool operator()(pll a, pll b) {
        return a.second > b.second;
    }
};

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    while (M--) {
        ll u, v, w;
        cin >> u >> v >> w;
        E[v].push_back({ u,w });
    }
    while (K--) {
        ll u;
        cin >> u;
        E[0].push_back({ u,0 });
    }

    ll ans = 0;
    ll ansidx = 0;
    pq<pll, vector<pll>, cmp> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        ll cur = q.top().first;
        ll dist = q.top().second;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (dist > ans) {
            ans = dist;
            ansidx = cur;
        }
        else if (dist == ans) {
            ansidx = min(ansidx, cur);
        }
        for (int i = 0; i < E[cur].size(); i++) {
            if (visited[E[cur][i].first]) continue;
            q.push({ E[cur][i].first, E[cur][i].second + dist });
        }
    }
    cout << ansidx << endl << ans;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }

    return 0;
}