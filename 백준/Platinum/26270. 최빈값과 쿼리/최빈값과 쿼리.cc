// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
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
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int arr[200001];
vector<int> v[200001];
int tree[800000];
int len[200001];

void update(int node, int start, int end, int idx, int val) {
    if (idx > end || idx < start) return;
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val); update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return inf;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return min(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int tc) {

    int N, K, Q;
    cin >> N >> K >> Q;
    for (int i = 1; i <= N; i++) {
        len[i] = inf;
        int x;
        cin >> x;
        arr[i] = x;
        v[x].push_back(i);
        if (v[x].size() >= K) len[v[x][v[x].size() - K]] = i - v[x][v[x].size() - K] + 1;
    }
    for (int i = N - 1; i >= 1; i--) {
        len[i] = min(len[i], len[i + 1] + 1);
    }
    for (int i = 1; i <= N; i++) update(1, 1, N, i, len[i]);

    while (Q--) {
        int l, r;
        cin >> l >> r;
        if (len[l] > r - l + 1) {
            cout << -1 << endl;
            continue;
        }

        int s = K;
        int e = r - l + 1;
        while (s < e) {
            int m = (s + e) / 2;
            if (get(1, 1, N, l, r - m + 1) <= m) e = m;
            else s = m + 1;
        }

        cout << s << endl;



    }

    



}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}