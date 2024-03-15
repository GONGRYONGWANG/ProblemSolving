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


int N, P, K;

vector<pii> E[1001];
bool visited[1001];

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

void solve() {

    cin >> N >> P >> K;
    for (int i = 0; i < P; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < E[cur].size(); i++) {
            if (visited[E[cur][i].first]) continue;
            q.push(E[cur][i].first);
            visited[E[cur][i].first] = true;
        }
    }
    if (!visited[N]) {
        cout << -1;
        return;
    }


    int l = 0;
    int r = 1000000;
    while (l < r) {
        int m = (l + r) / 2;
        fill(visited, visited + N + 1, false);
        deque<pii> q;
        q.push_back({ 1,0 });
        while (!q.empty()) {
            int cur = q.front().first;
            int k = q.front().second;
            q.pop_front();
            if (k > K || visited[cur]) continue;
            visited[cur] = true;
            for (int i = 0; i < E[cur].size(); i++) {
                int nx = E[cur][i].first;
                if (E[cur][i].second > m) {
                    q.push_back({ nx,k + 1 });
                }
                else {
                    q.push_front({ nx,k });
                }
            }
        }
        if (!visited[N]) l = m + 1;
        else r = m;
    }
    cout << r;


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