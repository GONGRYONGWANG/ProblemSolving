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

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

int ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

int visited[61][61][61];

vector<int> d[6] = { {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9} };

void solve() {

    ll N;
    cin >> N;
    
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a;
    if (N >= 2) cin >> b;
    if (N == 3) cin >> c;

    queue<vector<int>> q;
    q.push({ a,b,c });
    visited[a][b][c] = 1;
    while (!q.empty()) {
        int x, y, z;
        x = q.front()[0];
        y = q.front()[1];
        z = q.front()[2];
        q.pop();
        for (int df = 0; df < 6; df++) {
            if (visited[max(x - d[df][0], 0)][max(y - d[df][1], 0)][max(z - d[df][2], 0)]) continue;
            visited[max(x - d[df][0], 0)][max(y - d[df][1], 0)][max(z - d[df][2], 0)] = visited[x][y][z] + 1;
            q.push({ max(x - d[df][0], 0), max(y - d[df][1], 0), max(z - d[df][2], 0) });
        }
    }

    cout << visited[0][0][0] - 1;

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
