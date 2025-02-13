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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

pll arr[201];
ld dist[201][201];

ld getdist(pll a, pll b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool onroad(pll a, pll b, pll c) {
    if (a.first == b.first) {
        if (c.first != a.first) return false;
        if (c.second<min(a.second, b.second) || c.second>max(a.second, b.second)) return false;
        return true;
    }
    if (a.first > b.first) swap(a, b);
    if (c.first <= a.first || c.first >= b.first) return false;
    if ((c.second - a.second) * (b.first - a.first) == (c.first - a.first) * (b.second - a.second)) return true;

    return false;
}

void solve(int tc) {

    int N;
    cin >> N;
    arr[0] = { 0,0 };
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = dist[v][u] = getdist(arr[u], arr[v]);
    }
    
    for (int k = 0; k <= N; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    pii ans;
    ld ret = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            bool b = false;
            for (int k = 0; k <= N; k++) {
                if (k == i || k == j) continue;
                if (onroad(arr[i], arr[j], arr[k])) b = true;
            }
            if (b) continue;
            if (dist[i][j] - getdist(arr[i], arr[j]) > ret) {
                ans = { i,j }; ret = dist[i][j] - getdist(arr[i], arr[j]);
            }
        }
    }

    if (ret == 0) {
        cout << -1;
        return;
    }
    cout << ans.first << " " << ans.second;






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