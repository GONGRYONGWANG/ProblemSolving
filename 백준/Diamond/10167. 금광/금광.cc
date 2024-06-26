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


// F[];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x];
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


struct treeNode {
    treeNode() {}
    treeNode(ll sum, ll mx, ll lmx, ll rmx) : sum(sum), mx(mx), lmx(lmx), rmx(rmx) {}
    ll sum, mx, lmx, rmx;
};

treeNode mer(treeNode t1, treeNode t2) {
    treeNode ret;
    ret.sum = t1.sum + t2.sum;
    ret.mx = max(t1.mx, t2.mx);
    ret.mx = max(ret.mx, t1.rmx + max(t2.lmx, 0ll));
    ret.mx = max(ret.mx, t2.lmx + max(t1.rmx, 0ll));
    ret.lmx = max(t1.lmx, t1.sum + t2.lmx);
    ret.rmx = max(t2.rmx, t2.sum + t1.rmx);
    return ret;
}

treeNode tree[12000];

void update(int node, int start, int end, int target, ll val) {
    if (target > end || target < start) return;
    if (start == end) {
        ll nxt = tree[node].sum + val;
        tree[node] = { nxt,nxt,nxt,nxt };
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, target, val);
    update(node * 2 + 1, mid + 1, end, target, val);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void solve() {
    int N;
    cin >> N;
    vector<vector<ll>> arr(N);
    set<int> xs;
    set<int> ys;
    unordered_map<int, int> compx, compy;
    for (int i = 0; i < N; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        arr[i] = { x,y,w };
        xs.insert(x);
        ys.insert(y);
    }

    int xcnt = 0;
    for (auto iter = xs.begin(); iter != xs.end(); iter++) {
        xcnt += 1;
        compx[*iter] = xcnt;
    }

    int ycnt = 0;
    for (auto iter = ys.begin(); iter != ys.end(); iter++) {
        ycnt += 1;
        compy[*iter] = ycnt;
    }

    for (int i = 0; i < N; i++) {
        arr[i][0] = compx[arr[i][0]];
        arr[i][1] = compy[arr[i][1]];
    }

    sort(arr.begin(), arr.end());

    ll ans = 0;

    for (int i = 1; i <= xcnt; i++) {

        for (int j = 0; j < 4 * ycnt; j++) {
            tree[j] = { 0,0,0,0 };
        }

        int idx = 0;
        while (arr[idx][0] != i) {
            idx += 1;
        }

        for (int j = i; j <= xcnt; j++) {
            while (idx != N && arr[idx][0] == j) {
                update(1, 1, ycnt, arr[idx][1], arr[idx][2]);
                idx += 1;
            }
            ans = max(ans, tree[1].mx);

        }
    }

    cout << ans;


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
