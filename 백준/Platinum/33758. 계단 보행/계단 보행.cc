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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
///////////////////////////////////////////////////////////////


gp_hash_table<int, vector<pii>> E[50001];
gp_hash_table<int, int> visited[50001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        E[u][x - 1].push_back({ v,x });
        E[v][x - 1].push_back({ u,x });
        E[u][x + 1].push_back({ v,x });
        E[v][x + 1].push_back({ u,x });
    }

    vector<int> ret(N + 1, -1);

    queue<pii> q;

    for (int x = 0; x <= M; x++) {
        for (auto [v, nx] : E[1][x]) {
            if(visited[v][nx]) continue;
            visited[v][nx] = 1;
            q.push({ v,nx });
        }
    }

    while (!q.empty()) {
        auto [u, x] = q.front();
        q.pop();
        if (ret[u] == -1) ret[u] = visited[u][x];
        for (auto [v, nx] : E[u][x]) {
            if (visited[v][nx]) continue;
            visited[v][nx] = visited[u][x] + 1;
            q.push({ v,nx });
        }
    }

    for (int i = 1; i <= N; i++) cout << ret[i] << " ";


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