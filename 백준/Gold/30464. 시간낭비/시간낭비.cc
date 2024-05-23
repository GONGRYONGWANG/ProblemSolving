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

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

int N;

vector<pii> E[200000][3];
int cnt[200000][3];
int dist[200000][3];



void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (i == N - 1) continue;
        for (int j = 0; j <= 2; j++) {
            int nx = i;
            if (j % 2) nx -= x;
            else nx += x;
            if (nx >= 0 && nx < N) {
                E[i][j].push_back({ nx,j });
                cnt[nx][j] += 1;
            }
            if (j != 0) {
                cnt[i][j - 1] += 1;
            }
        }
    }

    queue<pii> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 2; j++) {
            dist[i][j] = -inf;
            if (cnt[i][j]) continue;
            q.push({ i,j });
        }
    }
    dist[0][2] = 0;



    while (!q.empty()) {
        int cur = q.front().first;
        int k = q.front().second;
        q.pop();

        for (pii e : E[cur][k]) {
            int nx = e.first;
            int nk = e.second;
            cnt[nx][nk] -= 1;
            dist[nx][nk] = max(dist[nx][nk], dist[cur][k] + 1);
            if (cnt[nx][nk] == 0) {
                q.push({ nx,nk });
            }
        }
        if (k != 0) {
            cnt[cur][k - 1] -= 1;
            dist[cur][k - 1] = max(dist[cur][k - 1], dist[cur][k]);
            if (cnt[cur][k - 1] == 0) {
                q.push({ cur,k - 1 });
            }
        }
    }
    int ans = -1;
    for (int j = 0; j <= 2; j++) {
        ans = max(ans, dist[N - 1][j]);
    }
    cout << ans;

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
