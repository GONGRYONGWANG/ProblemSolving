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




bool notprime[1000001];
bool ret[78498];
unordered_map<int, int> m;
int cnt;
void solve() {
    int N;
    cin >> N;
    vector<int> prime;
    for (ll i = 2; i <= 1000000; i++) {
        if (notprime[i]) continue;
        prime.push_back(i);
        m[i] = prime.size() - 1;
        for (ll j = i * i; j <= 1000000; j += i) {
            notprime[j] = true;
        }
    }
    cnt = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int idx = 0;
        while (notprime[x] && idx<prime.size()) {
            if (x % prime[idx]) {
                idx += 1;
                continue;
            }
            x /= prime[idx];
            ret[idx] = !ret[idx];
            if (ret[idx]) cnt += 1;
            else cnt -= 1;
        }
        if (x != 1) {
            idx = m[x];
            ret[idx] = !ret[idx];
            if (ret[idx]) cnt += 1;
            else cnt -= 1;
        }
        if (cnt == 0) cout << "DA";
        else cout << "NE";
        cout << endl;
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

