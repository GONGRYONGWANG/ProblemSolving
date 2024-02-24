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

string debug = "ans: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

//////////////////////////////////////////////////////////////////////////////////////

ll mod = 1000000007;
ll DP[5001];
ll COMB[5001][5001];

ll comb(int n, int r){
    if (r == 0) return 1;
    if (n == r) return 1;
    if (n < r) return 0;
    if (COMB[n][r] != -1) return COMB[n][r];
    return COMB[n][r] = (comb(n - 1, r) + comb(n - 1, r - 1)) % mod;
}

ll dp(int n) {
    if (DP[n] != -1) return DP[n];
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += comb(n, i) * dp(n - i) % mod;
        ret %= mod;
    }
    return DP[n] = ret;
}
void solve() {
    int N, K;
    cin >> N >> K;

    ll ret = comb(N - 1, K - 1) * dp(K - 1) % mod;
    if (N - K != 0) {
        ret = ret * 2 % mod;
    }
    ret = ret * dp(N - K) % mod;
    cout << ret << endl;

}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    for (int i = 0; i <= 5000; i++) {
        DP[i] = -1;
        for (int j = 0; j <= 5000; j++) {
            COMB[i][j] = -1;
        }
    }
    DP[0] = 1;

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}