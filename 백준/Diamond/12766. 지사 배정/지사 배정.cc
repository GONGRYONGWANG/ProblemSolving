// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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
///////////////////////////////////////////////////////////////



vector<pll> E[5001];
vector<pll> rE[5001];
struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

ll dist[5001];

vector<ll> arr;
ll DP[5002][5002];

void dnc(int s, int e, int ogl, int r, int k) {
    if (s > e) return;
    int m = (s + e) / 2;
    int l = ogl;
    l = max(l, m);

    ll psum = 0;
    for (int i = m; i <= l; i++) psum += arr[i];

    int mnidx = l; ll mn = psum * (l - m) + DP[l + 1][k - 1];

    for (int i = l + 1; i <= r; i++) {
        psum += arr[i];
        ll ret = psum * (i - m) + DP[i + 1][k - 1];
        if (ret < mn) {
            mn = ret;
            mnidx = i;
        }
    }

    DP[m][k] = mn;
    dnc(s, m - 1, ogl, mnidx, k); dnc(m + 1, e, mnidx, r, k);
}

void solve(int tc) {

    int N, B, S, R;
    cin >> N >> B >> S >> R;

    while (R--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        rE[v].push_back({ u,w });
    }

    pq<pll, vector<pll>, cmp> q;
    q.push({ B + 1,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (dist[x]) continue;
        dist[x] = d;
        for (pll& e : E[x]) {
            if (dist[e.first]) continue;
            q.push({ e.first, e.second + d });
        }
    }

    arr.resize(B, 0);
    for (int i = 1; i <= B; i++) {
        arr[i - 1] += dist[i] - 1;
    }

    for (int i = 1; i <= N; i++) dist[i] = 0;

    q.push({ B + 1,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (dist[x]) continue;
        dist[x] = d;
        for (pll& e : rE[x]) {
            if (dist[e.first]) continue;
            q.push({ e.first, e.second + d });
        }
    }

    for (int i = 1; i <= B; i++) {
        arr[i - 1] += dist[i] - 1;
    }

    sort(arr.begin(), arr.end());

    ll psum = 0;
    for (int i = 0; i < B; i++) {
        psum += arr[B - 1 - i];
        DP[B - 1 - i][1] = psum * i;
    }

    for (int k = 2; k <= S; k++) dnc(0, B - 1, 0, B - 1, k);

    cout << DP[0][S];

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