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
int depth[100001];

int sqrtN;
vector<int> Frag[100001];

vector<vector<int>> F;
vector<int> FragParent;

void dfs(int x) {
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
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

int blk[100001];
bool col[100001];

void updateFrag(int Fnum) {
    for (int x : F[Fnum]) {
        if (parent[x] == FragParent[Fnum]) {
            if (col[x]) blk[x] = x;
            else blk[x] = 0;
        }
        else {
            blk[x] = blk[parent[x]];
            if (blk[x] != 0) continue;
            if (col[x]) blk[x] = x;
        }
    }
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

    dfs(1);
    F.push_back(Frag[1]);
    FragParent.push_back(0);
    reverse(F.begin(), F.end());
    reverse(FragParent.begin(), FragParent.end());
    vector<int> FragDepth(F.size());
    vector<int> Fragnum(N + 1);
    for (int i = 0; i < F.size(); i++) {
        reverse(F[i].begin(), F[i].end());

        if (i == 0) FragDepth[i] = 0;
        else FragDepth[i] = FragDepth[Fragnum[FragParent[i]]] + 1;

        for (int x : F[i]) {
            Fragnum[x] = i;
            blk[x] = 0;
            col[x] = false; // white
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
        else {
            int v;
            cin >> v;
            int ans = -1;
            while (v != 0) {
                if (blk[v] != 0) ans = blk[v];
                v = FragParent[Fragnum[v]];
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