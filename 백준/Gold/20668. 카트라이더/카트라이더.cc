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


ll DP[10001][11];
vector<vector<ll>> E[10001];

struct cmp {
    bool operator()(vector<ll>& a, vector<ll>& b) {
        return a[2] > b[2];
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        ll u, v, l, k;
        cin >> u >> v >> l >> k;
        l *= 2520;
        E[u].push_back({ v,l,k });
        E[v].push_back({ u,l,k });
    }

    pq<vector<ll>, vector<vector<ll>>, cmp> q;
    q.push({ 1,1,1 });
    q.push({ 1,2,1 });
    while (!q.empty()) {
        int x = q.top()[0];
        int s = q.top()[1];
        ll t = q.top()[2];
        q.pop();
        if (DP[x][s]) continue;
        DP[x][s] = t;
        if (x == N) {
            cout << fixed;
            cout.precision(9);
            cout << ld(t - 1) / 2520;
            return;
        }
        for (vector<ll> e : E[x]) {
            if (s > e[2]) continue;
            int nx = e[0]; ll nt = t + e[1] / s;
            if (s != 1 && !DP[nx][s - 1]) q.push({ nx,s - 1,nt });
            if (!DP[nx][s]) q.push({ nx,s,nt });
            if (!DP[nx][s + 1])q.push({ nx,s + 1,nt });
        }
    }

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