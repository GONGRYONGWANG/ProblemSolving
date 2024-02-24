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

int N, M;
vector<int> child[100001];
pair<int, int> lr[100001];
int idx;

int tree[400000];
int lazy[400000];

void dfs(int node) {
    idx += 1;
    lr[node].first = idx;
    for (int next : child[node]) {
        dfs(next);
    }
    lr[node].second = idx;
}

int merge(int t1, int t2) {
    return t1 + t2;
}

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void praise(int node, int start, int end, int left, int right, int w) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    else if (left <= start && right >= end) {
        lazy[node] += w;
        lazyProp(node, start, end);
    }
    else {
        int mid = (start + end) / 2;
        praise(node * 2, start, mid, left, right, w);
        praise(node * 2 + 1, mid + 1, end, left, right, w);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
}

int get(int node, int start, int end, int target) {
    lazyProp(node, start, end);
    if (target > end || target < start) return 0;
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, target) + get(node * 2 + 1, mid + 1, end, target);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int x;
    cin >> x;
    for (int i = 2; i <= N; i++) {
        cin >> x;
        child[x].push_back(i);
    }
    idx = 0;
    dfs(1); 
    for (int i = 0; i < M; i++) {
        int a, n, w;
        cin >> a;
        if (a == 1) {
            cin >> n >> w;
            praise(1, 1, N, lr[n].first, lr[n].second, w);
        }
        else {
            cin >> n;
            cout << get(1, 1, N, lr[n].first) << endl;
        }
    }


    return 0;
}