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

vector<int> E[250001];
int parent[250001][18];
int depth[250001];

void dfs(int x) {
    for (int nx : E[x]) {
        if (nx == parent[x][0]) continue;
        parent[nx][0] = x;
        depth[nx] = depth[x] + 1;
        dfs(nx);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    for (int i = 0; i < 18; i++) {
        if (d & (1 << i)) a = parent[a][i];
    }
    if (a == b) return a;
    for (int i = 17; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];

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

    dfs(1);

    for (int j = 1; j < 18; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t, u, v, k, l;
        cin >> t >> u >> v >> k;
        if (t == 1) {
            if (depth[k] < depth[lca(u, v)]) {
                cout << "YES";
            }
            else if (lca(u, k) == k || lca(v, k) == k) {
                cout << "NO";
            }
            else cout << "YES";
            cout << endl;
        }
        else {
            cin >> l;
            if (depth[l] > depth[k]) swap(k, l);
            if (depth[k] <= depth[lca(u, v)]) {
                cout << "YES";
            }
            else if (lca(u, k) == k || lca(v, k) == k) {
                cout << "NO";
            }
            else cout << "YES";
            cout << endl;
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