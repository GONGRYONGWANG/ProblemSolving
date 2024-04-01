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

ll fastpow(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * fastpow(x, n - 1, mod) % mod;
    ll half = fastpow(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return fastpow(x, mod - 2, mod);
}




//////////////////////////////////////////////////////////////////////////////////////

int tree[400000];
int arr[100001];
int lazy[400000];

int makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = min(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
}

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];
    if (start != end) {
        int mid = (start + end) / 2;
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

int find0(int node, int start, int end) {
    lazyProp(node, start, end);
    if (tree[node] != 0) return -1;
    if (start == end) return start;
    int mid = (start + end) / 2;
    int r = find0(node * 2 + 1, mid + 1, end);
    if (r != -1) {
        return r;
    }
    int l = find0(node * 2, start, mid);
    return l;
}

void update(int node, int start, int end, int target) {
    lazyProp(node, start, end);
    if (target<start || target>end) return;
    if (start == end) {
        tree[node] = inf;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, target);
    update(node * 2 + 1, mid + 1, end, target);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void sub(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] -= 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    sub(node * 2, start, mid, left, right);
    sub(node * 2 + 1, mid + 1, end, left, right);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}



void solve() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    makeTree(1, 1, N);

    vector<int> ans(N + 1);
    for (int i = 0; i < N; i++) {
        int t = find0(1, 1, N);
        ans[t] = h[i];
        update(1, 1, N, t);
        sub(1, 1, N, t, N);
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
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
