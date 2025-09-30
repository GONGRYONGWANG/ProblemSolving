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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int parent[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {
    
    int N, M, T;
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<tuple<ll, int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, s;
        cin >> u >> v >> s;
        edges[i] = { s,u,v };
    }
    sort(edges.begin(), edges.end());

    ll ans = 0;
    ll cnt = N;
    ll t = 1;
    for (auto& [s, u, v] : edges) {
        ans += (s - t) * cnt;
        if (findp(u) != findp(v)) {
            cnt -= 1;
            parent[findp(u)] = findp(v);
        }
        t = s;
    }

    ans += (T - t + 1) * cnt;

    cout << ans;

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