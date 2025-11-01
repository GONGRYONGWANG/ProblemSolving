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
#include<chrono>
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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


vector<int> E[200001];
int parent[200001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}
int depth[200001];
int root[200001];

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) parent[i] = i;

    int s, t;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (findp(a) == findp(b)) {
            s = a; t = b;
            continue;
        }
        E[a].push_back(b);
        E[b].push_back(a);
        parent[findp(a)] = findp(b);
    }

    parent[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (nx == parent[x]) continue;
            parent[nx] = x;
            q.push(nx);
            depth[nx] = depth[x] + 1;
        }
    }
    
    root[t] = t;
    root[s] = s;
    q.push(t); q.push(s);
    while (s != t) {
        if (depth[s] > depth[t]) {
            s = parent[s];
            root[s] = s;
            q.push(s);
        }
        else {
            t = parent[t];
            root[t] = t;
            q.push(t);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (root[nx]) continue;
            root[nx] = root[x];
            q.push(nx);
        }
    }


    while (Q--) {
        int u, v;
        cin >> u >> v;
        if (root[u] == root[v]) cout << 1;
        else cout << 2;
        cout << endl;
    }












    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}