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

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

//////////////////////////////////////////////////////////////////////////////////////

int N;
bool visited[10];
int ans[7]; // h,w,e,o,l,r,d
int coef[7] = { 10000,10000,1000,1001,120,100,1 };
bool dfs(int x) {

    if (x == 7) {

        int ret = 0;
        for (int i = 0; i < 7; i++) {
            ret += ans[i] * coef[i];
        }

        if (ret == N) {
            return true;
        }
        else return false;
    }

    for (int i = 0; i <= 9; i++) {
        if (x == 0 || x == 1) {
            if (i == 0) continue;
        }

        if (visited[i]) continue;
        visited[i] = true;

        ans[x] = i;
        if (dfs(x + 1)) {
            return true;
        }

        visited[i] = false;
    }
    return false;
}


void solve() {
    cin >> N;
    if (dfs(0)) {
        cout << "  ";
        cout << ans[0] << ans[2] << ans[4] << ans[4] << ans[3] << endl;
        cout << "+ ";
        cout << ans[1] << ans[3] << ans[5] << ans[4] << ans[6] << endl;
        cout << "-------" << endl;
        cout << " ";
        if (N < 100000) cout << " ";
        cout << N;
    }
    else {
        cout << "No Answer";
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
