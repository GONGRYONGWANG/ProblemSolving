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


int parent[200001];
vector<int> child[200001];
int depth[200001];

int sqrtN;
vector<vector<int>> F;
vector<int> Frag[200001];
vector<int> FragParent;

void dfs(int x) {
    for (int nx : child[x]) {
        depth[nx] = depth[x] + 1;
        dfs(nx);
        for (int d : Frag[nx]) {
            Frag[x].push_back(d);
        }
        if (Frag[x].size() >= sqrtN) {
            F.push_back(Frag[x]);
            Frag[x].clear();
            FragParent.push_back(x);
        }
    }
    Frag[x].push_back(x);
}

int Fragnum[200001];
bool toFragParent[200001];

void updateFrag(int Fnum) {
    for (int x : F[Fnum]) {
        if (parent[x] == FragParent[Fnum]) toFragParent[x] = true;
        else toFragParent[x] = toFragParent[parent[x]];
    }
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;
    sqrtN = sqrt(N);
    for (int i = 2; i <= N; i++) {
        cin >> parent[i];
        child[parent[i]].push_back(i);
    }

    depth[1] = 0;
    dfs(1);
    F.push_back(Frag[1]);
    FragParent.push_back(0);

    reverse(F.begin(), F.end());
    reverse(FragParent.begin(), FragParent.end());
    vector<int> FragDepth(F.size());

    for (int i = 0; i < F.size(); i++) {
        reverse(F[i].begin(), F[i].end());

        if (i == 0) FragDepth[i] = 0;
        else FragDepth[i] = FragDepth[Fragnum[FragParent[i]]] + 1;
        
        for (int x : F[i]) {
            Fragnum[x] = i;
            toFragParent[x] = true;
        }
    }

    while (Q--) {
        int b, c, d;
        cin >> b >> c >> d;
        int u = b; int v = c;

        if (FragDepth[Fragnum[u]] < FragDepth[Fragnum[v]]) swap(u, v);
        while (FragDepth[Fragnum[u]] != FragDepth[Fragnum[v]]) {
            if (!toFragParent[u]) goto no;
            u = FragParent[Fragnum[u]];
        }
        while (Fragnum[u] != Fragnum[v]) {
            if (!toFragParent[u] || !toFragParent[v]) goto no;
            u = FragParent[Fragnum[u]];
            v = FragParent[Fragnum[v]];
        }

        if (depth[u] < depth[v]) swap(u, v);
        while (depth[u] != depth[v]) {
            if (!parent[u]) goto no;
            u = parent[u];
        }
        while (u != v) {
            if (!parent[u] || !parent[v]) goto no;
            u = parent[u]; v = parent[v];
        }

        cout << "YES" << endl;
        if (d) {
            parent[b] = 0;
            updateFrag(Fragnum[b]);
        }
        continue;
    no:
        cout << "NO" << endl;
        if (d) {
            parent[c] = 0;
            updateFrag(Fragnum[c]);
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