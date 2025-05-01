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
///////////////////////////////////////////////////////////////

int N, K;
vector<pii> arr;
int nx[100000];
int DP[100000][301][2];
int dp(int x, int n, bool b) {
    if (x == N || n == 0) return 0;
    if (DP[x][n][b] != -1) return DP[x][n][b];
    if (!b) return DP[x][n][b] = max(dp(x + 1, n, false), dp(x, n - 1, true) + arr[x].second - arr[x].first + 1);
    return DP[x][n][b] = max(dp(nx[x], n, false), 
        dp(nx[x] - 1, n - 1, true) + arr[nx[x] - 1].second - arr[nx[x] - 1].first + 1 - (arr[x].second - arr[nx[x] - 1].first + 1));
}

void solve(int tc) {
    
    cin >> N >> K;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        m[l] = max(m[l], r);
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        arr.push_back(*it);
        while (next(it) != m.end() && it->second >= next(it)->second) m.erase(next(it));
    }

    N = arr.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            DP[i][j][false] = DP[i][j][true] = -1;
        }
    }

    int idx = 0;
    for (int i = 0; i < N; i++) {
        while (idx != N && arr[idx].first <= arr[i].second) idx += 1;
        nx[i] = idx;
    }

    for (int i = 1; i <= K; i++) {
        cout << dp(0, i, false) << endl;
    }



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