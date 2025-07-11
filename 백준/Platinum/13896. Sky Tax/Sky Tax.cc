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

int sz[100001];
int depth[100001];
int parent[100001][17];
vector<int> E[100001];

void dfs(int x) {
    sz[x] = 1;
    for (int nx : E[x]) {
        if (nx == parent[x][0]) continue;
        parent[nx][0] = x;
        depth[nx] = depth[x] + 1;
        dfs(nx);
        sz[x] += sz[nx];
    }
}


void solve(int tc) {

    int N, Q, R;
    cin >> N >> Q >> R;

    for (int i = 1; i <= N; i++) E[i].clear();  

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    parent[R][0] = 0;
    depth[R] = 0;
    dfs(R);

    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    

    cout << "Case #" << tc << ":" << endl;

    while (Q--) {
        int s, u;
        cin >> s >> u;
        if (s == 0) {
            R = u;
        }
        else {
            int v = R;
            if (u == v) {
                cout << N << endl;
                continue;
            }

            if (depth[u] >= depth[v]) {
                cout << sz[u] << endl;
                continue;
            }

            int d = depth[v] - depth[u] - 1;
            for (int i = 0; i < 17; i++) {
                if (d & (1 << i)) v = parent[v][i];
            }

            if (parent[v][0] != u) {
                cout << sz[u] << endl;
                continue;
            }

            cout << N - sz[v] << endl;

        }
    }





}
    


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}