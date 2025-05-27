// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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


vector<int> E[101];
vector<int> rE[101];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        rE[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        vector<bool> visited(N + 1, false);
        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nx : E[x]) {
                if (visited[nx]) continue;
                visited[nx] = true;
                q.push(nx);
            }
        }
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nx : rE[x]) {
                if (visited[nx]) continue;
                visited[nx] = true;
                q.push(nx);
            }
        }
        ans += 1;
        for (int j = 1; j <= N; j++) {
            if (!visited[j]) {
                ans -= 1;
                break;
            }
        }
    }
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