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

ll arr[100001];
treeNode tree[400000];

treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { arr[start], arr[start], arr[start], arr[start] };
    }
    int mid = (start + end) / 2;
    return tree[node] = mer(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
}

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return { 0,-INF,-INF,-INF };
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}


void solve() {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    makeTree(1, 1, N);

    int M;
    cin >> M;
    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (y1 < x2) {
            if (x2 == y1 + 1) {
                cout << get(1, 1, N, x1, y1).rmx + get(1, 1, N, x2, y2).lmx;
                cout << endl;
                continue;
            }
            else {
                cout << get(1, 1, N, x1, y1).rmx + get(1, 1, N, y1 + 1, x2 - 1).sum + get(1, 1, N, x2, y2).lmx;
                cout << endl;
                continue;
            }
        }

        ll ret = get(1, 1, N, x2, y1).mx;
        if (x1 != x2) {
            ret = max(ret, max(0ll, get(1, 1, N, x1, x2 - 1).rmx) + get(1, 1, N, x2, y2).lmx);
        }
        if (y1 != y2) {
            ret = max(ret, get(1, 1, N, x1, y1).rmx + max(0ll, get(1, 1, N, y1 + 1, y2).lmx));
        }
        cout << ret << endl;
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
