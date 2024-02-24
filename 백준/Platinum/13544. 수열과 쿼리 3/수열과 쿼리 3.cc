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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

struct treeNode {
    treeNode() {}
    treeNode(vector<ll> v) : v(v) {};
    vector<ll> v;
};

int N, M;
ll arr[100001];
treeNode tree[400000];

treeNode treeMerge(treeNode t1, treeNode t2) {
    vector<ll> tv(t1.v.size() + t2.v.size());
    merge( t1.v.begin(),t1.v.end(), t2.v.begin(), t2.v.end(), tv.begin());
    return { tv };
}

treeNode makeTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = { {arr[start]} };
    }
    else {
        int mid = (start + end) / 2;
        return tree[node] = treeMerge(makeTree(node * 2, start, mid), makeTree(node * 2 + 1, mid + 1, end));
    }
}

int getK(int node, int start, int end, int left, int right, int k) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) {
        return tree[node].v.end() - upper_bound(tree[node].v.begin(), tree[node].v.end(), k);
    }
    int mid = (start + end) / 2;
    return getK(node * 2, start, mid, left, right, k) + getK(node * 2 + 1, mid + 1, end, left, right, k);
}

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    makeTree(1, 1, N);
    ll la = 0;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        la = getK(1, 1, N, a ^ la, b ^ la, c ^ la);
        cout << la << endl;
    }
    return 0;
}