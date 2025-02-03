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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////



void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<vector<pii>> E(N + 1);
    int R;
    cin >> R;
    for (int i = 0; i < R; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
    }

    int l = 1;
    int r = 1e8;
    while (l < r) {
        int m = (l + r) / 2;
        vector<int> K = arr;
        vector<bool> visited(N + 1, false);
        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (K[i] <= m) {
                q.push(i);
                visited[i] = true;
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cnt += 1;
            for (pii& e : E[x]) {
                if (visited[e.first]) continue;
                K[e.first] -= e.second;
                if (K[e.first] <= m) {
                    visited[e.first] = true;
                    q.push(e.first);
                }
            }
        }

        if (cnt >= M) r = m;
        else l = m + 1;
    }

    cout << l;






}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}