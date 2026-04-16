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

/////////////////////////////////////////////////////////////////////////////////////

struct treeNode {
    treeNode() {}
    treeNode(ll sz, ll sz2) : sz(sz), sz2(sz2) {}
    ll sz = 0;
    ll sz2 = 0;
};

treeNode tree[400000];
ll lazy[400000];


void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node].sz2 += tree[node].sz * lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

ll get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node].sz2;
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

void updatesz(int node, int start, int end, int target) {
    lazyProp(node, start, end);
    if (target > end || target < start) return;
    tree[node].sz += 1;
    if (start != end) {
        int mid = (start + end) / 2;
        updatesz(node * 2, start, mid, target);
        updatesz(node * 2 + 1, mid + 1, end, target);
    }
}

void updatesz2(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] += 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    updatesz2(node * 2, start, mid, left, right);
    updatesz2(node * 2 + 1, mid + 1, end, left, right);
    tree[node].sz2 = tree[node * 2].sz2 + tree[node * 2 + 1].sz2;
}

int N;


void solve() {
    cin >> N;

    map<int, vector<int>> m;
    map<int, int> compressy;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        m[x].push_back(y);
        compressy[y] = 1;
    }

    int cnt = 1;
    for (auto iter = compressy.begin(); iter != compressy.end(); iter++) {
        iter->second = cnt;
        cnt += 1;
    }

    ll ans = 0;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        for (auto it = (iter->second).begin(); it != (iter->second).end(); it++) {
            *it = compressy[*it];
            if (*it != 1) {
                ans += get(1, 1, N, 1, (*it) - 1);
            }
        }
        for (auto it = (iter->second).begin(); it != (iter->second).end(); it++) {
            if (*it != N) {
                updatesz2(1, 1, N, (*it) + 1, N);
            }
        }
        for (auto it = (iter->second).begin(); it != (iter->second).end(); it++) {
            updatesz(1, 1, N, *it);
        }
    }

    cout << ans;

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
