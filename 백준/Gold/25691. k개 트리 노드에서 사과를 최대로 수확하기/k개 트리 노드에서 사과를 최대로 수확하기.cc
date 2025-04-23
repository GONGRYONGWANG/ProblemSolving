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

vector<int> child[18];
int DP[17][18];
void dfs(int x) {
    for (int nx : child[x]) {
        dfs(nx);
        for (int i = 17; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                DP[x][i] = min(DP[x][i], DP[x][j] + DP[nx][i - j]);
            }
        }
    }
}

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int p, c;
        cin >> p >> c;
        child[p].push_back(c);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < 18; j++) {
            DP[i][j] = inf;
        }
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        DP[i][x] = 1;
    }

    dfs(0);


    for (int i = N; i >= 0; i--) {
        if (DP[0][i] <= K) {
            cout << i;
            return;
        }
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