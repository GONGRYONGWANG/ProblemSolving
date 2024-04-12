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


ll ptow(ll p){
    if (p <= 200) {
        return p / 2;
    }
    p -= 200;
    if (p <= 9900 * 3) {
        return 100 + p / 3;
    }
    p -= 9900 * 3;
    if (p <= 990000 * 5) {
        return 10000 + p / 5;
    }
    p -= 990000 * 5;
    return 1000000 + p / 7;
}

ll wtop(ll w) {
    ll ret = 0;
    if (w <= 100) {
        return w * 2;
    }
    w -= 100;
    if (w <= 9900) {
        return 200 + w * 3;
    }
    w -= 9900;
    if (w <= 990000) {
        return 200 + 9900 * 3 + w * 5;
    }
    w -= 990000;
    return 200 + 9900 * 3 + 990000 * 5 + w * 7;
}



void solve() {

    ll A, B;
    cin >> A >> B;
    while (A != 0) {
        ll w = ptow(A);
        ll l = 0;
        ll r = w / 2;
        while (l < r) {
            ll m = (l + r) / 2;
            if (wtop(w - m) - wtop(m) > B) {
                l = m + 1;
            }
            else if (wtop(w - m) - wtop(m) < B) {
                r = m - 1;
            }
            else {
                l = r = m;
            }
        }
        cout << wtop(l) << endl;


        cin >> A >> B;
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
