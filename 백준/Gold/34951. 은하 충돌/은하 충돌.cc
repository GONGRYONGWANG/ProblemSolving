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


vector<pll> E[400001];
int ind[400001];
ll arr[400001];
ll S[400001];

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    while (K--) {
        ll u, v, w;
        cin >> u >> v >> w;
        if (u < 0) u = -u + N;
        if (v < 0) v = -v + N;
        E[v].push_back({ u,w });
        ind[u] += 1;
    }

    for (int i = N + 1; i <= N+M; i++) {
        cin >> S[i];
    }


    int G;
    cin >> G;

    queue<int> q;
    for (int i = 1; i <= N + M; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        arr[x] += S[x];

        for (auto& [nx, d] : E[x]) {
            arr[nx] = max(arr[nx], arr[x]);
            ind[nx] -= 1;
            if (ind[nx] == 0) q.push(nx);
        }
    }

    
    for (int i = 1; i <= N + M; i++) {
        for (auto [v, w] : E[i]) {
            if (i == G || v == G) {
                if (w <= arr[1]) {
                    cout << "HAPPY";
                    return;
                }
            }
        }
    }

    cout << "SAD";




    // cout << "Case #" << tc << ": " << ret << endl;
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