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



struct cmp {
    bool operator()(pair<pii,vector<int>> a, pair<pii, vector<int>> b) {
        return a.first.second > b.first.second;
    }
};

int cnt = 0;

void solve() {
    cnt += 1;
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> E(M);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        E[x].push_back({ y,z });
        E[y].push_back({ x,z });
    }

    cout << "Case #" << cnt << ": ";


    vector<bool> visited(M);
    pq<pair<pii, vector<int>>, vector<pair<pii,vector<int>>>, cmp> q;
    q.push({ {0,0},{0} });
    while (!q.empty()) {
        int cur = q.top().first.first;
        int d = q.top().first.second;
        vector<int> v = q.top().second;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (cur == M-1) {
            for (int i = 0; i<v.size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            return;
        }
        for (int i = 0; i < E[cur].size(); i++) {
            int nx = E[cur][i].first;
            int nd = d + E[cur][i].second;
            if (visited[nx]) continue;
            vector<int> nv = v;
            nv.push_back(nx);
            q.push({ { nx,nd }, nv });
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

