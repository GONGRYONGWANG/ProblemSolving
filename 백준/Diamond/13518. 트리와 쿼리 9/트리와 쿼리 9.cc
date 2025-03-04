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

int val[100001];
vector<int> E[100001];

int L[100001];
int R[100001];
int arr[200001];
int depth[100001];
int parent[100001][17];

int idx = 1;
void dfs(int x) {
    L[x] = idx;
    arr[idx] = x;
    idx += 1;
    for (int nx : E[x]) {
        if (nx == parent[x][0]) continue;
        depth[nx] = depth[x] + 1;
        parent[nx][0] = x;
        dfs(nx);
    }
    R[x] = idx;
    arr[idx] = x;
    idx += 1;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int d = depth[u] - depth[v];
    for (int i = 0; i < 17; i++) {
        if (d & (1 << i)) u = parent[u][i];
    }
    if (u == v) return u;
    for (int i = 16; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}


void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> val[i];
    int sqrtN = sqrt(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    dfs(1);

    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int Q;
    cin >> Q;
    vector<vector<int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        int l, r;
        if (L[u] > L[v]) swap(u, v);
        if (R[v] <= R[u]) {
            l = L[u]; r = L[v];
        }
        else {
            l = R[u]; r = L[v];
        }
        query[i] = { l,r,i };
    }

    auto cmp = [&](vector<int>& a, vector<int>& b) {
        if (a[0] / sqrtN == b[0] / sqrtN) return a[1] < b[1];
        return a[0] < b[0];
    };

    sort(query.begin(), query.end(), cmp);

    vector<int> ans(Q);
    vector<int> cnt(1000001, 0);
    vector<bool> inbck(N + 1, false);
    int s = 1; int e = 1;
    int ret = 0;
    for (int i = 0; i < Q; i++) {
        int l = query[i][0]; int r = query[i][1];
        int u = arr[l]; int v = arr[r];
        r += 1;

        while (l < s) {
            s -= 1;
            inbck[arr[s]] = !inbck[arr[s]];
            if (inbck[arr[s]]) {
                cnt[val[arr[s]]] += 1;
                if (cnt[val[arr[s]]] == 1) ret += 1;
            }
            else {
                cnt[val[arr[s]]] -= 1;
                if (cnt[val[arr[s]]] == 0) ret -= 1;
            }
        }
        while (e < r) {
            inbck[arr[e]] = !inbck[arr[e]];
            if (inbck[arr[e]]) {
                cnt[val[arr[e]]] += 1;
                if (cnt[val[arr[e]]] == 1) ret += 1;
            }
            else {
                cnt[val[arr[e]]] -= 1;
                if (cnt[val[arr[e]]] == 0) ret -= 1;
            }
            e += 1;
        }
        while (s < l) {
            inbck[arr[s]] = !inbck[arr[s]];
            if (inbck[arr[s]]) {
                cnt[val[arr[s]]] += 1;
                if (cnt[val[arr[s]]] == 1) ret += 1;
            }
            else {
                cnt[val[arr[s]]] -= 1;
                if (cnt[val[arr[s]]] == 0) ret -= 1;
            }
            s += 1;
        }
        while (r < e) {
            e -= 1;
            inbck[arr[e]] = !inbck[arr[e]];
            if (inbck[arr[e]]) {
                cnt[val[arr[e]]] += 1;
                if (cnt[val[arr[e]]] == 1) ret += 1;
            }
            else {
                cnt[val[arr[e]]] -= 1;
                if (cnt[val[arr[e]]] == 0) ret -= 1;
            }
        }

        if (l == R[u] && cnt[val[lca(u, v)]] == 0) {
            ans[query[i][2]] = ret + 1;
        }
        else ans[query[i][2]] = ret;
    }

    for (int x : ans) cout << x << endl;

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