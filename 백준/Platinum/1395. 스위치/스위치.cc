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


int tree[400000];
bool lazy[400000];

int makeTree(int node, int start, int end) {
    if (start == end) return tree[node] = 1;
    int mid = (start + end) / 2;
    return makeTree(node * 2, start, mid) + makeTree(node * 2, mid + 1, end);
}

void lazyProp(int node, int start, int end) {
    if (!lazy[node]) return;
    tree[node] = (end - start + 1) - tree[node];
    if (start != end) {
        int mid = (start + end) / 2;
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2 + 1] = !lazy[node * 2 + 1];
    }
    lazy[node] = false;
}

void update(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = !lazy[node];
        lazyProp(node, start, end);
        return;
    }
    else {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right);
        update(node * 2 + 1, mid + 1, end, left, right);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
        return;
    }
}

int get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    while (M--) {
        int o, s, t;
        cin >> o >> s >> t;
        if (o == 0) {
            update(1, 1, N, s, t);
        }
        else {
            cout << get(1, 1, N, s, t) << endl;
        }
    }

    return 0;
}