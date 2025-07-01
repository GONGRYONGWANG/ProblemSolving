// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
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
#define INF ll(4e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int tree[4000004];
int lazy[4000004];

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, int val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] += val;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val); update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

struct cmp {
    bool operator()(pair<pii, pii>& a, pair<pii, pii>& b) {
        return a.second.first < b.second.first;
    }
};


void solve(int tc) {

    int x, y, z, w;
    cin >> x >> y >> z >> w;

    int D;
    cin >> D;

    int N;
    cin >> N;

    vector<pair<pii, pii>> arr(N);
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += 1; b += 1; c += 1; d += 1;
        arr[i] = { {a,b},{c,d} };
    }

    sort(arr.rbegin(), arr.rend());

    int ans = 0;

    pq<pair<pii, pii>, vector<pair<pii, pii>>, cmp> q;

    for (int i = 0; i < N; i++) {
        auto [a, b] = arr[i].first;
        auto [c, d] = arr[i].second;
        if (a - c > D || b - d > D) continue;
        update(1, 1, 1000001, b, d + D, 1);
        q.push(arr[i]);
        while (!q.empty() && q.top().second.first - a > D) {
            update(1, 1, 1000001, q.top().first.second, q.top().second.second + D, -1);
            q.pop();
        }
        ans = max(ans, tree[1]);
    }

    cout << ans;
    






}
    


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}