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


ll cnt[100001];
int arr[100001];
vector<int> E[100001];
int parent[100001];
ll ret[100001];
map<int, ll> m[100001];
void dfs(int x) {

    m[x][arr[x]] = 1;
    ret[x] = cnt[arr[x]] - 1;

    for (int nx : E[x]) {
        if (parent[x] == nx) continue;
        parent[nx] = x;
        dfs(nx);
        if (m[x].size() < m[nx].size()) {
            ret[x] = ret[nx];
            swap(m[x], m[nx]);
        }
        for (auto it = m[nx].begin(); it != m[nx].end(); it++) {
            auto [col, count] = *it;
            ret[x] -= m[x][col] * (cnt[col] - m[x][col]);
            m[x][col] += count;
            ret[x] += m[x][col] * (cnt[col] - m[x][col]);
        }
    }
}

void solve(int tc) {


    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        cnt[arr[i]] += 1;
    }
    vector<pii> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = { u,v };
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1);

    for (auto [u, v] : edges) {
        if (u == parent[v]) u = v;
        cout << ret[u] << endl;
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