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




/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}
*/

//////////////////////////////////////////////////////////////////////////////////////

int arr[100001];
int tree[400000];

int makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = makeTree(node * 2, start, mid) * makeTree(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int target, int val) {
    if (target<start || target>end) return;
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, target, val);
    update(node * 2 + 1, mid + 1, end, target, val);
    tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) * get(node * 2 + 1, mid + 1, end, left, right);
}

int N, M;
void solve() {
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] > 0) arr[i] = 1;
        if (arr[i] < 0) arr[i] = -1;
    }
    makeTree(1, 1, N);
    while (M--) {
        char x;
        cin >> x;
        if (x == 'C') {
            int target, v;
            cin >> target >> v;
            if (v > 0) v = 1;
            if (v < 0) v = -1;
            update(1, 1, N, target, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            int ret = get(1, 1, N, l, r);
            if (ret > 0) cout << '+';
            else if (ret < 0) cout << '-';
            else cout << 0;
        }
    }
    cout << endl;



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    // cin >> T;
    // T = 1;
    while (cin >> N >> M) {
        solve();
    }

    return 0;
}