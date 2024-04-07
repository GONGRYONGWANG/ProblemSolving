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

vector<int> bucket[317];
int arr[100001];

void solve() {
    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        bucket[i / 316].push_back(arr[i]);
    }

    for (int i = 0; i <= 316; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    cin >> M;
    while (M--) {
        int a, l, r, k;
        cin >> a;
        if (a == 1) {
            cin >> l >> r >> k;
            int ret = 0;
            for (int i = l; i / 316 == l / 316 && i <= r; i++) {
                if (arr[i] > k) ret += 1;
            }
            for (int i = l / 316 + 1; i < r / 316; i++) {
                ret += bucket[i].end() - upper_bound(bucket[i].begin(), bucket[i].end(), k);
            }
            for (int i = max(r / 316 * 316, (l / 316 + 1) * 316); i <= r; i++) {
                if (arr[i] > k) ret += 1;
            }
            cout << ret << endl;
        }
        else {
            cin >> l >> k;
            bucket[l / 316].erase(find(bucket[l / 316].begin(), bucket[l / 316].end(), arr[l]));
            arr[l] = k;
            bucket[l / 316].insert(lower_bound(bucket[l / 316].begin(), bucket[l / 316].end(), arr[l]), arr[l]);
        }
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
