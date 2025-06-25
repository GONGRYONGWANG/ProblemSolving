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
const int inf = 1e9 + 7;
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
bool coordinatecmp(pll a, pll b) {
    // 1. 사분면 비교 (y > 0 이면 위쪽, y == 0 이면 x > 0 이면 오른쪽)
    auto half = [](pair<long long, long long> p) {
        if (p.second > 0) return 1;
        if (p.second < 0) return 0;
        return p.first > 0 ? 1 : 0;
    };

    int ha = half(a), hb = half(b);
    if (ha != hb) return ha > hb;

    // 2. 같은 반평면이면 cross product 비교
    return a.first * b.second - a.second * b.first > 0;
}

///////////////////////////////////////////////////////////////


bool cmp(vector<ll> a, vector<ll> b) {
    return coordinatecmp(make_pair( a[0],a[1] ), make_pair( b[0],b[1] ));
}

struct pqcmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

ll tree[400000];
ll lazy[400000];

void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = val;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void solve(int tc) {
    
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> arr(N);
    for (int i = 0; i < N; i++) {
        ll x, y, s;
        cin >> x >> y >> s;
        arr[i] = { x,y,s };
    }
    sort(arr.begin(), arr.end(), cmp);

    vector<int> ridx(N);
    pq<pll, vector<pll>, pqcmp> q;

    int idx = 0;
    for (int i = 0; i < N; i++) {
        arr.push_back(arr[i]);
        while (idx != N + i && arr[i][0] * arr[idx][1] - arr[i][1] * arr[idx][0] >= 0 && arr[i][0] * arr[idx][0] + arr[i][1] * arr[idx][1] >= 0) {
            idx += 1;
        }
        ridx[i] = idx;
        q.push({ i, arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1] });
    }

    vector<ll> P(M);
    for (int i = 0; i < M; i++) cin >> P[i];
    sort(P.begin(), P.end());

    ll ans = -INF;
    for (ll p : P) {
        while (!q.empty() && q.top().second <= p) {
            int l = q.top().first + 1;
            int r = ridx[q.top().first];
            update(1, 1, N, l, min(r, N), arr[q.top().first][2]);
            if (r > N) update(1, 1, N, 1, r - N, arr[q.top().first][2]);
            q.pop();
        }
        ans = max(ans, tree[1] - p);
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