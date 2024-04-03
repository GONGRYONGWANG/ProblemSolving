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
    ll ret= 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}




//////////////////////////////////////////////////////////////////////////////////////

pii parent[2001];

pii find_p(int x) {
    if (parent[x].first == x) return parent[x];
    return parent[x] = { find_p(parent[x].first).first, parent[x].second * find_p(parent[x].first).second };
}

bool mer(int a, int b) {
    if (find_p(a).first != find_p(b).first) {
        parent[find_p(b).first] = { find_p(a).first , -find_p(a).second * find_p(b).second};
        return 1;
    }
    if (find_p(a).second == find_p(b).second) {
        return 0;
    }
    return 1;
}


struct cmp {
    bool operator()(vector<int> a, vector<int>b) {
        return a[2] > b[2];
    }
};



void solve() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        parent[i] = { i,1 };
    }

    pq<vector<int>, vector<vector<int>>, cmp> q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (i < j) {
                q.push({ i,j,x });
            }
        }
    }

    while (!q.empty()) {
        int a = q.top()[0];
        int b = q.top()[1];
        if (!mer(a,b)) {
            cout << q.top()[2];
            return;
        }
        q.pop();
    }
    cout << 0;

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
