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

vector<vector<ll>> E[200001];

bool visited[200001];

struct cmp {
    bool operator()(vector<ll> a, vector<ll> b) {
        if (a[1] == b[1]) return a[2] > b[2];
        return a[1] > b[1];
    }
};

void solve() {

    ll N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll x, y, z, w;
        cin >> x >> y >> z >> w;
        E[x].push_back({ y, z, w });
        E[y].push_back({ x,z,w });
    }
    pq<vector<ll>, vector<vector<ll>>, cmp> q;
    q.push({ 1,0,0 });
    vector<ll> ansmemo;
    ll ans = 0;
    while(!q.empty()) {
        vector<ll> node = q.top();
        q.pop();
        ll cur = node[0];
        ll memo = node[1];
        ll cost = node[2];
        if (visited[cur]) continue;
        visited[cur] = true;
        ansmemo.push_back(memo);
        ans += cost;
        for (int i = 0; i < E[cur].size(); i++) {
            ll nx = E[cur][i][0];
            ll nm = E[cur][i][1];
            ll nc = E[cur][i][2];
            if (visited[nx]) continue;
            q.push({ nx,nm,nc });
        }
    }
    if (ansmemo.size() != N) {
        cout << -1;
        return;
    }
    sort(ansmemo.begin(), ansmemo.end());
    for (int i = 0; i < N; i++) {
        if (ansmemo[i] == 0) continue;
        cout << ansmemo[i];
    }
    cout << " ";
    cout << ans;
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