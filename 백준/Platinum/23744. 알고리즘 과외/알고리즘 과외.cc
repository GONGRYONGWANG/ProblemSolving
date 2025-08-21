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
#include<chrono>
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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


pii tree[800000];
int arr[200001];
pii lr[200001];

void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        if (tree[node].first == arr[x]) tree[node] = { inf,-inf };
        else tree[node] = { arr[x],arr[x] };
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x); update(node * 2 + 1, mid + 1, end, x);
    tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
    tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
}

pii get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return { inf,-inf };
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    pii l = get(node * 2, start, mid, left, right);
    pii r = get(node * 2 + 1, mid + 1, end, left, right);
    return { min(l.first,r.first),max(l.second,r.second) };
}


void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 1; i < 4 * N; i++) tree[i] = { inf,-inf };

    vector<pii> io;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        int l, r;
        cin >> l >> r;
        lr[i] = { l,r };
        io.push_back({ i - r,i });
        io.push_back({ i - l + 1,i });
        io.push_back({ i + l,i });
        io.push_back({ i + r + 1,i });
    }

    sort(io.begin(), io.end());

    int ans = -1;

    int idx = 0;
    for (int i = 1; i <= N; i++) {
        while(idx != 4 * N && io[idx].first <= i) {
            update(1, 1, N, io[idx].second);
            idx += 1;
        }

        auto [l, r] = lr[i];

        if (i - l >= 1) {
            pii ret = get(1, 1, N, max(1, i - r), i - l);
            ans = max(ans, arr[i] - ret.first);
            ans = max(ans, ret.second - arr[i]);
        }

        if (i + l <= N) {
            pii ret = get(1, 1, N, i + l, min(i + r, N));
            ans = max(ans, arr[i] - ret.first);
            ans = max(ans, ret.second - arr[i]);
        }

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