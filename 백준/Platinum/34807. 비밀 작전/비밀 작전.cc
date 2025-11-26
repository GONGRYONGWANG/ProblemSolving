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


ll arr[100001];
vector<int> E[100001];

int parent[100001];
ll sz[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, M; ll X;
    cin >> N >> M >> X;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int Q;
    cin >> Q;
    vector<int> v(Q);
    for (int& x : v) cin >> x;

    set<int> st;
    for (int i = 1; i <= N; i++) st.insert(i);
    for (int x : v) st.erase(x);

    vector<pll> init;
    for (int x : st) init.push_back({ arr[x],x });

    int l = 0;
    int r = Q;
    while (l < r) {
        for (int i = 1; i <= N; i++) {
            parent[i] = 0;
            sz[i] = 1;
        }
        int m = (l + r + 1) / 2;
        vector<pll> A = init;
        for (int i = m; i < Q; i++) {
            A.push_back({ arr[v[i]], v[i] });
        }

        sort(A.rbegin(), A.rend());

        bool flag = false;

        for (auto& [p, x] : A) {
            parent[x] = x;
            for (int nx : E[x]) {
                if (parent[nx] == 0) continue;
                if (findp(nx) == findp(x)) continue;
                sz[findp(x)] += sz[findp(nx)];
                parent[findp(nx)] = findp(x);
            }
            if (X % p == 0 && sz[findp(x)] >= X / p) flag = true;
        }

        if (flag) l = m;
        else r = m - 1;
    }


    for (int i = 1; i <= Q; i++) {
        if (i > l) cout << 0;
        else cout << 1;
        cout << endl;
    }


    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}