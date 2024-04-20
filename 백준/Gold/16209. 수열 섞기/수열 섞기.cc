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





void solve() {

    int N;
    cin >> N;
    vector<int> pos, neg;
    int zeros = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 0) pos.push_back(x);
        else if (x < 0) neg.push_back(x);
        else zeros += 1;
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    bool b = true;

    deque<int> posq;
    for (int i = 0; i < pos.size(); i++) {
        if (b)posq.push_back(pos[i]);
        else posq.push_front(pos[i]);
        b = !b;
    }

    b = true;
    deque<int> negq;
    for (int i = 0; i < neg.size(); i++) {
        if (b)negq.push_back(neg[i]);
        else negq.push_front(neg[i]);
        b = !b;
    }

    if (pos.size() % 2 == 0) {
        reverse(posq.begin(), posq.end());
    }

    for (int i = 0; i < pos.size(); i++) {
        cout << posq[i] << " ";
    }
    for (int i = 0; i < zeros; i++) {
        cout << 0 << " ";
    }

    if (neg.size() % 2) {
        reverse(negq.begin(), negq.end());
    }

    for (int i = 0; i < neg.size(); i++) {
        cout << negq[i] << " ";
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
