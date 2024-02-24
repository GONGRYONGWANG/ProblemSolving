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
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
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
const double pi = 3.14159265358979323846;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] > b[2];
}

struct treeNode {
    treeNode() {}
    treeNode(ll sum) : sum(sum) {};
    ll sum;
};

int N, M;
pll arr[100001];
treeNode tree[400000];
ll lazy1[400000];
ll lazy2[400000];
int arrtonode[100001];

treeNode merge(treeNode t1, treeNode t2) {
    return { t1.sum+t2.sum };
}


treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        arrtonode[start] = node;
        return tree[node] = {0};
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = merge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
}

void add(int node) {
    tree[node].sum += 1;
    if (node == 1) return;
    return add(node / 2);
}

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return {0};
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return merge(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

vector<int> Q[100001];
int ans[100001];
void init() {
    cin >> N;
    fill(lazy1, lazy1 + 800001, (1 << 20) - 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1, arr + N + 1, greater<pll>());
    cin >> M;
    for (int i = 0; i < M; i++) {
        vector<int> v(4);
        cin >> v[0] >> v[1] >> v[2];
        v[3] = i;
        Q[i] = v;
    }
    sort(Q, Q + M, cmp);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    makeTree(1, 1, N);
    int idx = 1;
    for (int i = 0; i < M; i++) {
        vector<int> q = Q[i];
        int l, r, k;
        l = q[0];
        r = q[1];
        k = q[2];
        while (idx <=N && k < arr[idx].first) {
            add(arrtonode[arr[idx].second]);
            idx += 1;
        }
        ans[Q[i][3]] = get(1,1,N,Q[i][0],Q[i][1]).sum;
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}