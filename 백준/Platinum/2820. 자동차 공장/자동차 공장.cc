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
#include<complex> // complex
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
const int inf = 1e9;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
//const double pi = 3.14159265358979323846;

vector<int> child[500001];
pair<int, int> lr[500001];
int idx;

ll tree[2000000];
ll lazy[2000000];

void dfs(int node) {
    idx += 1;
    lr[node].first = idx;
    for (int next : child[node]) {
        dfs(next);
    }
    lr[node].second = idx;
}

ll merge(ll t1, ll t2) {
    return t1 + t2;
}

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += ((ll)end - start + 1) * lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void add(int node, int start, int end, int left, int right, ll w) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        lazy[node] += w;
        lazyProp(node, start, end);
    }
    else {
        int mid = (start + end) / 2;
        add(node * 2, start, mid, left, right, w);
        add(node * 2 + 1, mid + 1, end, left, right, w);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
}

ll get(int node, int start, int end, int target) {
    lazyProp(node, start, end);
    if (target > end || target < start) return 0;
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, target) + get(node * 2 + 1, mid + 1, end, target);
}

int N, M;
ll arr[500001];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    cin >> arr[1];
    for (int i = 2; i <= N; i++) {
        cin >> arr[i];
        ll x;
        cin >> x;
        child[x].push_back(i);
    }
    idx = 0;
    dfs(1); 
    for (int i = 0; i <= N; i++) {
        add(1, 1, N, lr[i].first, lr[i].first, arr[i]);
    }
    for (int i = 0; i < M; i++) {
        char c;
        int n; 
        ll w;
        cin >> c;
        if (c=='p') {
            cin >> n >> w;
            if (lr[n].first != lr[n].second) {
                add(1, 1, N, lr[n].first + 1, lr[n].second, w);
            }
        }
        else {
            cin >> n;
            cout << get(1, 1, N, lr[n].first) << endl;
        }
    }


    return 0;
}