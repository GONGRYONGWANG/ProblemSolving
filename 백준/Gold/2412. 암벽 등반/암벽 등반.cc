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

unordered_map<int, int> m[200001];
pii arr[50001];
int visited[50001];

void solve() {
    int N, T;
    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = { x,y };
        m[y][x] = i;
    }
    arr[0] = { 0,0 };


    visited[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        int x = arr[cur].first;
        int y = arr[cur].second;
        q.pop();
        if (y == T) {
            cout << visited[cur] - 1;
            return;
        }
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx>1000000 || ny<0 || ny>T) continue;
                if (m[ny].count(nx) && !visited[m[ny][nx]]) {
                    q.push(m[ny][nx]);
                    visited[m[ny][nx]] = visited[cur] + 1;
                }
            }
        }
    }
    cout << -1;
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

