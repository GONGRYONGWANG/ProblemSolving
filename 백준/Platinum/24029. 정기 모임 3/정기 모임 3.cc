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
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

vector<int> E[200001];
int height[200001];
void getheight(int x, int p) {
    if (E[x].size() == 1 && x != 1) {
        height[x] = 1;
        return;
    }
    for (int nx : E[x]) {
        if (nx == p) continue;
        getheight(nx, x);
        height[x] = max(height[x], height[nx] + 1);
    }
}

int ret[200001];

int treewidth = 0;

void dfs(int x, int p, int c) {
    pii mx = { c,0 };
    vector<int> v;
    if (c != 0) v.push_back(c);
    for (int nx : E[x]) {
        if (nx == p) continue;
        int h = height[nx];
        if (h >= mx.first) mx = { h,mx.first };
        else if (h > mx.second) mx = { mx.first,h };
        v.push_back(h);
    }
    sort(v.begin(), v.end());

   /* cout << x << endl;
    for (int val : v) cout << val << " ";
    cout << endl; */

    for (int i = 0; i < v.size() - 1; i++) {
        ret[v[i] * 2] = max(ret[v[i] * 2], int(v.size()) - i);
    }
    for (int nx : E[x]) {
        if (nx == p) continue;
        int h = height[nx];
        if (h == mx.first) dfs(nx, x, mx.second + 1);
        else dfs(nx, x, mx.first + 1);
    }
    treewidth = max(treewidth, mx.first + mx.second);
}

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    getheight(1, -1);

    dfs(1, -1, 0);

    for (int i = N-1; i >= 1; i--) {
        ret[i] = max(ret[i], ret[i + 1]);
    }

    for (int i = 1; i <= N; i++) {
        if (i % 2) {
            if (i <= treewidth) cout << 2;
            else cout << 1;
            cout << endl;
        }
        else cout << max(1, ret[i]) << endl;
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