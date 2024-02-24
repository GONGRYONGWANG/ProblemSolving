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
int parent[100001];
pair<int, int> lr[100001];
int idx;

struct treeNode {
    treeNode(){}
    treeNode(int on, int off) : on(on), off(off) {}
    int on, off;
};

treeNode tree[400000];
int lazy[400000];

void dfs(int node) {
    idx += 1;
    lr[node].first = idx;
    for (int next : child[node]) {
        dfs(next);
    }
    lr[node].second = idx;
}

treeNode merge(treeNode t1, treeNode t2) {
    return { t1.on + t2.on, t1.off + t2.off };
}

treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { 1,0 };
    }
    int mid = (start + end) / 2;
    return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
}

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    if (lazy[node] == 1) {
        tree[node] = { tree[node].on + tree[node].off, 0 };
    }
    else {
        tree[node] = { 0, tree[node].on + tree[node].off };
    }
    if (start != end) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
}

void turn(int node, int start, int end, int left, int right, int x) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = x;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    turn(node * 2, start, mid, left, right, x);
    turn(node * 2 + 1, mid + 1, end, left, right, x);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    return;
}

int get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) {
        return tree[node].on;
    }
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int x;
    cin >> x;
    for (int i = 2; i <= N; i++) {
        cin >> x;
        child[x].push_back(i);
    }
    idx = 0;
    dfs(1);
    makeTree(1, 1, N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, n;
        cin >> a >> n;
        if (a == 1) {
            if (lr[n].first == lr[n].second) continue;
            turn(1, 1, N, lr[n].first + 1, lr[n].second, 1);
        }
        else if(a == 2) { 
            if (lr[n].first == lr[n].second) continue;
            turn(1, 1, N, lr[n].first + 1, lr[n].second, -1);
        }
        else {
            if (lr[n].first == lr[n].second) {
                cout << 0 <<endl;
                continue;
            }
            cout<< get(1, 1, N, lr[n].first + 1, lr[n].second) << endl;
        }
    }


    return 0;
}