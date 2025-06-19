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
///////////////////////////////////////////////////////////////

vector<int> E[10001];

void solve(int tc) {

    int N, M, Q, K;
    cin >> N >> M >> Q >> K;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    map<int, vector<int>> m;
    while (Q--) {
        int t, x;
        cin >> t >> x;
        m[t].push_back(x);
    }

    if (!m.count(K)) m[K] = {};

    vector<int> even(N + 1, -1), odd(N + 1, -1);
    even[1] = 0;

    int time = 0;
    for (auto it = m.begin(); it != m.end(); it++) {

        queue<pii> q;
        if (time % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                if (even[i] != -1) q.push({ i,time });
            }
        }
        else {
            for (int i = 1; i <= N; i++) {
                if (odd[i] != -1) q.push({ i,time });
            }
        }

        while (!q.empty() && q.front().second <= it->first) {
            auto [x, t] = q.front();
            q.pop();
            for (int nx : E[x]) {
                if (t % 2 == 0) {
                    if (odd[nx] != -1) continue;
                    odd[nx] = t + 1;
                    q.push({ nx, t + 1 });
                }
                else {
                    if (even[nx] != -1) continue;
                    even[nx] = t + 1;
                    q.push({ nx,t + 1 });
                }
            }
        }

        if ((it->first) % 2 == 0) {
            odd.clear(); odd.resize(N + 1, -1);
            for (int x : it->second) even[x] = -1;
        }
        else {
            even.clear(); even.resize(N + 1, -1);
            for (int x : it->second) odd[x] = -1;
        }

        time = it->first;

    }

    int ans = -1;
    for (int i = 1; i <= N; i++) {
        if (odd[i] != -1 || even[i] != -1) ans = max(ans, arr[i]);
    }

    cout << ans;
    if (ans == -1) return;

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (odd[i] == -1 && even[i] == -1) continue;
        if (arr[i] == ans) cnt += 1;
    }

    cout << " " << cnt;

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