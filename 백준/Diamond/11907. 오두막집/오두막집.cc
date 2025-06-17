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
///////////////////////////////////////////////////////////////

vector<pll> E[100001];
bool hut[100001];

int sz[100001];
bool visited[100001];

int getsz(int x, int p = -1) {
    sz[x] = 1;
    for (pll& e : E[x]) {
        int nx = e.first;
        if (nx == p || visited[nx]) continue;
        sz[x] += getsz(nx, x);
    }
    return sz[x];
}

int getcent(int x, int p, int s) {
    for (pll& e : E[x]) {
        int nx = e.first;
        if (nx == p || visited[nx]) continue;
        if (sz[nx] * 2 > s) return getcent(nx, x, s);
    }
    return x;
}

vector<vector<ll>> dist[100001];
vector<ll> dists[100001];

void dnc(int x, int prvcent = -1) {
    int cent = getcent(x, -1, getsz(x));

    visited[cent] = true;

    int branchidx = 0;
    queue<tuple<ll,ll,ll,ll>> q; // cur,prv, branch, dist
    for (pll& e : E[cent]) {
        int nx = e.first;
        if (visited[nx]) continue;
        branchidx += 1;
        q.push({ nx, cent, branchidx, e.second });
    }

    dist[cent].resize(branchidx + 1);
    if (hut[cent]) {
        dist[cent][0].push_back(0);
        dists[cent].push_back(0);
    }

    while (!q.empty()) {
        auto [cur, prv, branch, d] = q.front();
        q.pop();

        if (hut[cur]) {
            dist[cent][branch].push_back(d);
            dists[cent].push_back(d);
        }

        for (pll& e : E[cur]) {
            int nx = e.first;
            if (nx == prv || visited[nx]) continue;
            q.push({ nx, cur, branch, d + e.second });
        }
    }

    for (int i = 0; i <= branchidx; i++) sort(dist[cent][i].begin(), dist[cent][i].end());
    sort(dists[cent].begin(), dists[cent].end());

    for (pll& e : E[cent]) {
        int nx = e.first;
        if (visited[nx]) continue;
        dnc(nx, cent);
    }
}

ll N, M, K;

ll subget(int cent, ll m) {
    ll ret = 0;
    for (vector<ll>& v : dist[cent]) {
        for (ll x : v) {
            ret += upper_bound(dists[cent].begin(), dists[cent].end(), m - x) - dists[cent].begin();
            ret -= upper_bound(v.begin(), v.end(), m - x) - v.begin();
        }
    }
    ret /= 2;
    return ret;
}

ll get(ll m){
    ll ret = 0;
    for (int i = 1; i <= N; i++) ret += subget(i, m);
    return ret;
}

void solve(int tc) {

    cin >> N >> M >> K;

    for (int i = 2; i <= N; i++) {
        ll r, d;
        cin >> r >> d;
        E[i].push_back({ r,d });
        E[r].push_back({ i,d });
    }

    while (M--) {
        int x; cin >> x;
        hut[x] = true;
    }

    dnc(1);

    ll l = 1;
    ll r = INF;
    while (l < r) {
        ll m = (l + r) / 2;
        if (get(m) < K) l = m + 1;
        else r = m;
    }

    cout << l;

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