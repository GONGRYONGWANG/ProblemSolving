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


int cost[10001];
vector<int> E[10001];
int cnt[10001];
int dist[10001];

void solve() {
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        cin >> cnt[i];
        if (cnt[i] == 0) {
            q.push(i);
            dist[i] = cost[i];
        }
        for (int j = 0; j < cnt[i]; j++) {
            int x;
            cin >> x;
            E[x].push_back(i);
        }
    }

    int ans = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans = max(ans, dist[cur]);
        for (int i = 0; i < E[cur].size(); i++) {
            int nx = E[cur][i];
            dist[nx] = max(dist[nx], dist[cur] + cost[nx]);
            cnt[nx] -= 1;
            if (cnt[nx] == 0) q.push(nx);
        }
    }
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