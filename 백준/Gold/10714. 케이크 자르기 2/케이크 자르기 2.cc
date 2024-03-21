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

int N;
ll arr[2000];
ll DP[2000][2000];
ll dp(int l, int r) {
    if ((l+1)%N == r) return 0;
    if (l == r) return arr[l];
    if (DP[l][r]) return DP[l][r];

    if (arr[(l + N - 1) % N] > arr[r]) {
        DP[l][r] = arr[l] + dp((l + 2 * N - 2) % N, r);
    }
    else {
        DP[l][r] = arr[l] + dp((l + N - 1) % N, (r + 1) % N);
    }

    if (arr[l] > arr[(r + 1) % N]) {
        DP[l][r] = max(DP[l][r], arr[r] + dp((l + N - 1) % N, (r + 1) % N));
    }
    else {
        DP[l][r] = max(DP[l][r], arr[r] + dp(l % N, (r + 2) % N));
    }

    return DP[l][r];
}
void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if (N == 1) {
        cout << arr[0];
        return;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (arr[(i + N - 1) % N] > arr[(i + 1) % N]) {
            ans = max(ans, arr[i] + dp((i + 2 * N - 2) % N, (i + 1) % N));
        }
        else {
            ans = max(ans, arr[i] + dp((i + N - 1) % N, (i + 2) % N));
        }
    }
    cout << ans;
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