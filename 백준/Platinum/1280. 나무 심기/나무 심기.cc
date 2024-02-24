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

pll tree[800004]; // sz,sum

pll mer(pll a, pll b) {
    return { a.first + b.first, a.second + b.second };
}

void add(int node, ll start, ll end, ll target) {
    if (target<start || target>end) return;
    if (start == end) {
        tree[node].first += 1;
        tree[node].second += target;
    }
    else {
        ll mid = (start + end) / 2;
        add(node * 2, start, mid, target);
        add(node * 2 + 1, mid + 1, end, target);
        tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
    }
}

pll get(int node, ll start, ll end, ll left, ll right) {
    if (right<start || left>end) return { 0,0 };
    if (left <= start && right >= end) return tree[node];
    ll mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}


ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    ll ans = 1;
    ll x;
    cin >> x;
    x += 1;
    add(1, 1, 200001, x);
    N -= 1;
    while (N--) {
        cin >> x;
        x += 1;
        pll l = get(1, 1, 200001, 1, x);
        pll r = get(1, 1, 200001, x, 200001);
        ans = ans * ((l.first * x - l.second + r.second - r.first * x) % mod) % mod;
        add(1, 1, 200001, x);
    }
    cout << ans;
    return 0;
}