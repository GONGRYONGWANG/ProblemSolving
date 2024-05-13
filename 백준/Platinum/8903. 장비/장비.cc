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


int mx[32];
int arr[10000][32];

int DP[32][6];

int dp(int x, int n) {
    if (n == 1) return mx[x];
    if (DP[x][n] != -1) return DP[x][n];
    int ret = 0;
    for (int i = 1; i < 32; i++) {
        if ((x | i) == x) {
            ret = max(ret, mx[i] + dp(x - i, n - 1));
        }
    }
    return ret;
}

void solve() {

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < 32; i++) {
        mx[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 32; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j <= 5; j++) {
            DP[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            for (int k = 0; k < 32; k++) {
                if (k % (1 << (j + 1)) / (1 << j) == 1){
                    arr[i][k] += x;
                }
            }
        }

        for (int k = 0; k < 32; k++) {
            mx[k] = max(mx[k], arr[i][k]);
        }

    }

    cout << dp(31, min(K,5)) << endl;

}
//11111


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
