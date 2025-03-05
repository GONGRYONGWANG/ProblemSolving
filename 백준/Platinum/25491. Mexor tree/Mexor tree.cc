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

int arr[300001];
vector<int> E[300001];
int lazy[300001];
int parent[300001][19];
int depth[300001];

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int d = depth[u] - depth[v];
    for (int i = 0; i < 19; i++) {
        if (d & (1 << i)) u = parent[u][i];
    }
    if (u == v) return u;
    for (int i = 18; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void lazyProp(int x) {
    for (int nx : E[x]) {
        if (nx == parent[x][0]) continue;
        lazyProp(nx);
        lazy[x] ^= lazy[nx];
    }
    arr[x] ^= lazy[x];
}

int cnt[300001];
int bck[547];
int N;
int ans[300001];
void dfs(int x) {
    if (arr[x] <= N) {
        cnt[arr[x]] += 1;
        if (cnt[arr[x]] == 1) bck[arr[x] / 546] += 1;
    }
    for (int i = 0; ; i++) {
        if (bck[i] != 546) {
            for (int j = i * 546; j < (i + 1) * 546; j++) {
                if (!cnt[j]) {
                    ans[x] = j;
                    break;
                }
            }
            break;
        }
    }

    for (int nx : E[x]) {
        if (nx == parent[x][0]) continue;
        dfs(nx);
    }

    if (arr[x] <= N) {
        cnt[arr[x]] -= 1;
        if (cnt[arr[x]] == 0) bck[arr[x] / 546] -= 1;
    }

}

void solve(int tc) {

    int S;
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (nx == parent[x][0]) continue;
            parent[nx][0] = x;
            depth[nx] = depth[x] + 1;
            q.push(nx);
        }
    }

    for (int j = 1; j < 19; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int l = lca(x, y);
        lazy[x] ^= z; lazy[y] ^= z; 
        lazy[l] ^= z; lazy[parent[l][0]] ^= z;
    }

    lazyProp(S);
    
    dfs(S);

    for (int i = 1; i <= N; i++) cout << ans[i] << " ";

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