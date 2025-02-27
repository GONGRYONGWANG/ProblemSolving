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

vector<pii> E[100001];
int depth[100001];
pii parent[100001];

int sqrtN;
vector<int> Frag[100001];
vector<vector<int>> F;
vector<int> FragParent;

void dfs(int x) {
    for (pii& e : E[x]) {
        int nx = e.first;
        if (parent[x].first == nx) continue;
        parent[nx] = { x, e.second };
        depth[nx] = depth[x] + 1;
        dfs(nx);
        for (int d : Frag[nx]) {
            Frag[x].push_back(d);
        }
        if (Frag[x].size() >= sqrtN) {
            F.push_back(Frag[x]);
            FragParent.push_back(x);
            Frag[x].clear();
        }
    }
    Frag[x].push_back(x);
}


int Fragnum[100001];
int maxtoFragParent[100001];

void updateFrag(int Fnum) {
    for (int x : F[Fnum]) {
        if (parent[x].first == FragParent[Fnum]) maxtoFragParent[x] = parent[x].second;
        else maxtoFragParent[x] = max(parent[x].second, maxtoFragParent[parent[x].first]);
    }
}

void solve(int tc) {

    int N;
    cin >> N;
    sqrtN = sqrt(N);

    vector<pii> Earr(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
        Earr[i + 1] = { u,v };
    }


    depth[1] = 0;
    parent[1] = { 0,0 };
    dfs(1);

    F.push_back(Frag[1]);
    FragParent.push_back(0);

    reverse(F.begin(), F.end());
    reverse(FragParent.begin(), FragParent.end());
    vector<int> FragDepth(F.size());

    for (int i = 0; i < F.size(); i++) {
        if (i == 0) FragDepth[i] = 0;
        else FragDepth[i] = FragDepth[Fragnum[FragParent[i]]] + 1;
        reverse(F[i].begin(), F[i].end());
        for (int x : F[i]) {
            Fragnum[x] = i;
        }
        updateFrag(i);
    }

    int M;
    cin >> M;
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, c;
            cin >> i >> c;
            auto [u, v] = Earr[i];
            if (depth[u] < depth[v]) swap(u, v);
            parent[u].second = c;
            updateFrag(Fragnum[u]);
        }
        else {
            int u, v;
            cin >> u >> v;

            int ans = 0;
            while (FragDepth[Fragnum[u]] != FragDepth[Fragnum[v]]) {
                if (FragDepth[Fragnum[u]] < FragDepth[Fragnum[v]]) swap(u, v);
                ans = max(ans, maxtoFragParent[u]);
                u = FragParent[Fragnum[u]];
            }
            while (Fragnum[u] != Fragnum[v]) {
                ans = max(ans, maxtoFragParent[u]);
                u = FragParent[Fragnum[u]];
                ans = max(ans, maxtoFragParent[v]);
                v = FragParent[Fragnum[v]];
            }
            if (depth[u] < depth[v]) swap(u, v);
            while (depth[u] != depth[v]) {
                ans = max(ans, parent[u].second);
                u = parent[u].first;
            }
            while (u != v) {
                ans = max(ans, parent[u].second);
                u = parent[u].first;
                ans = max(ans, parent[v].second);
                v = parent[v].first;
            }
            cout << ans << endl;
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