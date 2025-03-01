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

vector<int> E[100001];
int parent[100001];
vector<int> tmpFrag[100001];
int sqrtN;
vector<vector<int>> Frag;
vector<int> FragParent;
vector<int> nodechildFrag[100001];
vector<vector<int>> FragchildFrag;
bool col[100001];
int Fragnum[100001];
int arr[100001];
vector<int> mx[2];

void dfs(int x) {
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
        dfs(nx);
        for (int d : tmpFrag[nx]) {
            tmpFrag[x].push_back(d);
        }
        if (tmpFrag[x].size() >= sqrtN) {
            Frag.push_back(tmpFrag[x]);
            FragParent.push_back(x);
            tmpFrag[x].clear();
        }
    }
    tmpFrag[x].push_back(x);
}

bool nodetoFragParent[100001];

void updateFrag(int Fnum) {
    mx[0][Fnum] = mx[1][Fnum] = 0;
    for (int x : Frag[Fnum]) {
        if (parent[x] == FragParent[Fnum]) nodetoFragParent[x] = true;
        else if (col[x] == col[parent[x]]) nodetoFragParent[x] = nodetoFragParent[parent[x]];
        else nodetoFragParent[x] = false;

        if (nodetoFragParent[x]) mx[col[x]][Fnum] = max(mx[col[x]][Fnum], arr[x]);
    }
}

vector<int> childinFrag[100001];

int dfsFrag(int Fnum, bool c) {
    int ret = mx[c][Fnum];
    for (int CF : FragchildFrag[Fnum]) {
        if (nodetoFragParent[FragParent[CF]] && col[FragParent[CF]] == c) ret = max(ret, dfsFrag(CF, c));
    }
    return ret;
}

int dfsnode(int x, bool c) {
    if (col[x] != c) return 0;
    int ret = arr[x];
    for (int nx : childinFrag[x]) ret = max(ret, dfsnode(nx, c));
    for (int CF : nodechildFrag[x]) ret = max(ret, dfsFrag(CF, c));
    return ret;
}


void solve(int tc) {

    int N;
    cin >> N;
    sqrtN = sqrt(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) cin >> col[i];
    for (int i = 1; i <= N; i++) cin >> arr[i];
    parent[1] = -1;
    dfs(1);
    Frag.push_back(tmpFrag[1]);
    FragParent.push_back(-1);
    reverse(Frag.begin(), Frag.end());
    reverse(FragParent.begin(), FragParent.end());

    mx[0].resize(Frag.size()); mx[1].resize(Frag.size());
    FragchildFrag.resize(Frag.size());

    for (int i = 0; i < Frag.size(); i++) {
        reverse(Frag[i].begin(), Frag[i].end());
        for (int x : Frag[i]) {
            Fragnum[x] = i;
        }
        updateFrag(i);
        if (FragParent[i] != -1) {
            nodechildFrag[FragParent[i]].push_back(i);
            FragchildFrag[Fragnum[FragParent[i]]].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int nx : E[i]) {
            if (nx == parent[i]) continue;
            if (Fragnum[i] != Fragnum[nx]) continue;
            childinFrag[i].push_back(nx);
        }
    }

    int M;
    cin >> M;
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            col[i] = !col[i];
            updateFrag(Fragnum[i]);
        }
        else if (t == 2) {
            int u;
            cin >> u;
            while (nodetoFragParent[u] && FragParent[Fragnum[u]] != -1 && col[u] == col[FragParent[Fragnum[u]]]) {
                u = FragParent[Fragnum[u]];
            }
            while (parent[u] != -1 && col[u] == col[parent[u]]) u = parent[u];
            cout << dfsnode(u, col[u]) << endl;

        }
        else {
            int u, w;
            cin >> u >> w;
            arr[u] = w;
            updateFrag(Fragnum[u]);
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