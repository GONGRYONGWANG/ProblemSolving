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

string DP[101];
string arr[8];

void solve() {
    int N;
    cin >> N;
    string ans = "9999999999999999999999";
    for (int i = 2; i <= min(7, N); i++) {
        string tmp = arr[i] + DP[N - i];
        if (tmp.length() < ans.length()) {
            ans = tmp;
            continue;
        }
        if (tmp.length() > ans.length()) continue;
        ans = min(ans, arr[i] + DP[N - i]);
    }
    cout << ans <<" ";
    
    if (N % 2) {
        cout << 7;
        N -= 3;
    }
    while (N) {
        cout << 1;
        N -= 2;
    }


    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    arr[2] = "1"; arr[3] = "7", arr[4] = "4", arr[5] = "2", arr[6] = "6", arr[7] = "8";
    DP[0] = ""; DP[1] = "999"; DP[2] = "1"; DP[3] = "7"; DP[4] = "4"; DP[5] = "2"; DP[6] = "0"; DP[7] = "8";
    for (int i = 8; i <= 100; i++) {
        DP[i] = "9999999999999999999999999999999999";
        for (int j = 1; j <= 7; j++) {
            string tmp = DP[i - j] + DP[j];
            if (tmp.length() < DP[i].length()) {
                DP[i] = tmp;
                continue;
            }
            if (tmp.length() > DP[i].length()) continue;
            DP[i] = min(DP[i], DP[i-j]+DP[j]);  
        }
    }


    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
