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

ll fastpow(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * fastpow(x, n - 1, mod) % mod;
    ll half = fastpow(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return fastpow(x, mod - 2, mod);
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


int arr[300000];
int DP[300000];

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = M - 1; i < min(2 * M - 1, N); i++) {
        DP[i] = arr[i] - arr[0];
    }


    vector<int> v;
    for (int i = 2 * M - 1; i < N; i++) {
        while (!v.empty() && DP[v.back()] >= DP[i - M]) {
            v.pop_back();
        }
        v.push_back(i - M);

        int l = 0;
        int r = v.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (DP[v[m]] >= arr[i] - arr[v[m] + 1]) {
                r = m;
            }
            else l = m + 1;
        }
        DP[i] = max(DP[v[l]], arr[i] - arr[v[l] + 1]);
        if (l != 0) {
            DP[i] = min(DP[i], max(DP[v[l-1]],arr[i] - arr[v[l - 1] + 1]));
        }
    }

    while (Q--) {
        int x;
        cin >> x;
        if (x >= DP[N - 1]) cout << 1;
        else cout << 0;
    }

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
