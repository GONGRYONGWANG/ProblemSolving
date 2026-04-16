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

ll tree[4000000];

void add(int node, int start, int end, int target, int val) {
    if (target<start || target>end) return;
    if (start == end) tree[node] += val;
    else {
        int mid = (start + end) / 2;
        add(node * 2, start, mid, target, val);
        add(node * 2 + 1, mid + 1, end, target, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

ll get(int node, int start, int end, int left, int right) {
    if (right < start || left>end) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    while (M--) {
        int x;
        cin >> x;
        if (x==1) {
            int p, v;
            cin >> p >> v;
            add(1, 1, N, p, v);
        }
        else {
            int p, q;
            cin >> p >> q;
            cout << get(1, 1, N, p, q) << endl;
        }
    }



    return 0;
}