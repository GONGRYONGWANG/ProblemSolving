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

struct VectorHasher {
    int operator()(const vector<int>& V) const {
        int hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

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

int ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////


vector<int> E[400001];
unordered_map<string, int> idx;
string ridx[400001];
int cnt[400001];

struct cmp {
    bool operator()(pii a, pii b) {
        if(a.second== b.second) return ridx[a.first] > ridx[b.first];
        return a.second > b.second;
    }
};

void solve() {

    int N;
    cin >> N;

    int index = 1;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        if (!idx[a]) {
            idx[a] = index;
            ridx[index] = a;
            index += 1;
        }
        if (!idx[b]) {
            idx[b] = index;
            ridx[index] = b;
            index += 1;
        }
        cnt[idx[b]] += 1;
        E[idx[a]].push_back(idx[b]);
    }

    pq<pii, vector<pii>, cmp> q;

    for (int i = 1; i <= index-1; i++) {
        if (cnt[i] == 0) q.push({ i,0 });
    }

    vector<int> ans;

    while (!q.empty()) {
        int cur = q.top().first;
        int depth = q.top().second;
        q.pop();
        ans.push_back(cur);
        for (int nx : E[cur]) {
            cnt[nx] -= 1;
            if (cnt[nx] == 0) q.push({ nx,depth + 1 });
        }
    }

    if (ans.size() != index - 1) {
        cout << -1;
        return;
    }
    for (int x : ans) {
        cout << ridx[x] << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
