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

struct treeNode {
    treeNode() {}
    treeNode(ll sz, ll a) : sz(sz), a(a) {}
    ll sz = 0;
    ll a =0;
};

treeNode mer(treeNode t1, treeNode t2) {
    return { t1.sz+t2.sz, t1.a + t2.a};
}

treeNode tree[4000004];

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return {0,0};
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}



void update(int node, int start, int end, int target, ll da) {
    if (target > end || target < start) return;
    if (start == end) {
        tree[node].sz += 1;
        tree[node].a += da;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, target, da);
    update(node * 2 + 1, mid + 1, end, target, da);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

bool cmp(pii a, pii b){
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve() {
    int N;
    cin >> N;
    vector<pii> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;
        arr[i].first += 1;
    }
    for (int j = 0; j < N; j++) {
        cin >> arr[j].second;
        arr[j].second += 1;
    }
    sort(arr.begin(), arr.end(), cmp);


    ll ans = 0;

    for (int i = 0; i < N; i++) {
        int x = arr[i].second;
        treeNode d = { 0,0 };
        if (x != 1) {
            d = get(1, 1, 1000001, 1, x - 1);
        }
        ll da = d.sz;
        ans += d.a;
        update(1, 1, 1000001, x, da);
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
