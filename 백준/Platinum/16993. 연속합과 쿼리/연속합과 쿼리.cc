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

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
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


struct treeNode {
    treeNode() {}
    treeNode(ll total, ll mx, ll l, ll r, ll maxval) : total(total), mx(mx), l(l), r(r), maxval(maxval) {}
    ll total;
    ll mx;
    ll l;
    ll r;
    ll maxval;
};

treeNode mer(treeNode t1, treeNode t2) {
    treeNode ret;
    ret.total = t1.total + t2.total;
    ret.l = max(t1.l, t1.total + t2.l);
    ret.r = max(t2.r, t2.total + t1.r);
    ret.maxval = max(t1.maxval, t2.maxval);
    ret.mx = max(max(ret.l, ret.r), max(t1.mx, t2.mx));
    ret.mx = max(ret.mx, t1.r + t2.l);
    return ret;
}


ll arr[100001];
treeNode tree[400000];

treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { arr[start], max(arr[start],(ll)0), max(arr[start],(ll)0), max(arr[start],(ll)0), arr[start] };
    }
    int mid = (start + end) / 2;
    return tree[node] = mer(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
}

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return { 0,0,0,0,-inf };
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
        int i, j;
        cin >> i >> j;
        treeNode t = get(1, 1, N, i, j);
        if (t.maxval < 0) {
            cout << t.maxval << endl;
            continue;
        }
        cout << t.mx << endl;
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
