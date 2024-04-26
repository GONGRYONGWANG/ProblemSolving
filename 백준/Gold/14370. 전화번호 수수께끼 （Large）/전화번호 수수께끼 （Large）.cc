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

int cnt;

void solve() {

    string s;
    cin >> s;
    unordered_map<char, int> st;
    for (int i = 0; i < s.length(); i++) {
        st[s[i]] += 1;
    }
    vector<int> ans(10, 0);
    ans[6] = st['X'];
    for (char x : "SIX") {
        st[x] -= ans[6];
    }
    ans[0] = st['Z'];
    for (char x : "ZERO") {
        st[x] -= ans[0];
    }
    ans[8] = st['G'];
    for (char x : "EIGHT") {
        st[x] -= ans[8];
    }
    ans[4] = st['U'];
    for (char x : "FOUR") {
        st[x] -= ans[4];
    }
    ans[2] = st['W'];
    for (char x : "TWO") {
        st[x] -= ans[2];
    }
    ans[1] = st['O'];
    for (char x : "ONE") {
        st[x] -= ans[1];
    }
    ans[5] = st['F'];
    for (char x : "FIVE") {
        st[x] -= ans[5];
    }
    ans[3] = st['T'];
    for (char x : "THREE") {
        st[x] -= ans[3];
    }
    ans[7] = st['S'];
    for (char x : "SEVEN") {
        st[x] -= ans[7];
    }
    ans[9] = st['E'];

    cnt += 1;
    cout << "Case #" << cnt << ": ";

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j < ans[i]; j++) {
            cout << i;
        }
    }
    cout << endl;

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cnt = 0;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
