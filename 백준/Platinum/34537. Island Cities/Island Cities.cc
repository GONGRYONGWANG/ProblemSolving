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


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int parent[50001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {
    
    int N, M, B;
    cin >> N >> M >> B;

    vector<tuple<ll, ll, ll, ll, ll>> edges(M);

    for (int i = 0; i < M; i++) {
        ll u, v, w, x, y;
        cin >> u >> v >> w >> x >> y;
        edges[i] = { u,v,w,x,y };
    }
    
    ll l = 1;
    ll r = 2e11;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        vector<tuple<ll, ll, ll>> E;
        for (int i = 1; i <= N; i++) parent[i] = i;
        for (auto& [u, v, w, x, y] : edges) {
            if (w >= m) E.push_back({ 0, u, v });
            else E.push_back({ (m - w + x - 1) / x * y,u,v });
        }
        sort(E.begin(), E.end());

        ll total = 0;
        for (auto& [w, u, v] : E) {
            if (findp(u) == findp(v)) continue;
            total += w;
            parent[findp(u)] = findp(v);
        }

        bool flag = (total <= B);
        for (int i = 1; i <= N; i++) flag &= (findp(1) == findp(i));

        if (flag) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    vector<tuple<ll, ll, ll, int>> E;
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int j = 0; j < M; j++) {
        auto& [u, v, w, x, y] = edges[j];
        if (w >= l) E.push_back({ 0, u, v, j });
        else E.push_back({ (l - w + x - 1) / x * y,u,v, j });
    }
    sort(E.begin(), E.end());

    vector<ll> ret(M, 0);
    for (auto& [w, u, v, i] : E) {
        if (findp(u) == findp(v)) continue;
        parent[findp(u)] = findp(v);
        auto& [a, b, c, d, y] = edges[i];
        ret[i] = w / y;
    }

    for (ll ans : ret) cout << ans << endl;






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