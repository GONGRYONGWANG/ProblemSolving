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
#define INF 1e18+7
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
vector<int> topol;

void dfs(int x) {
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
        dfs(nx);
    }
    topol.push_back(x);
}

void solve(int tc) {

    int N, M, P;
    cin >> N >> M >> P;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs(P);
    topol.pop_back();

    int l = 1;
    int r = N;
    while (l < r) {
        int m = (l + r) / 2;
        vector<int> DP(N + 1, 0);
        int ret = 0;
        for (int x : topol) {
            if (DP[x] == 0) {
                ret += 1;
                DP[x] = m;
            }
            DP[parent[x]] = max(DP[parent[x]], DP[x] - 1);
        }

        if (ret <= M) r = m;
        else l = m + 1;

    }

    if (l == N) cout << -1;
    else cout << l;





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