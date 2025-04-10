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
#define INF ll(1e18+7)
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


void solve(int tc) {

    string s;
    cin >> s;

    vector<pii> dp(4, { 0,0 }); // 0:00, 1:01, 2:10, 3:11
    for (char x : s) {
        vector<pii> nx(4, { inf,-inf });
        if (x == '1') {
            nx[1] = { min(dp[0].first,dp[2].first) + 1, max(dp[0].second,dp[2].second) + 1 };
            nx[3] = { dp[1].first + 1, dp[1].second + 1 };
        }
        else if (x == '0') {
            nx[0] = dp[2];
            nx[2] = { min(dp[1].first,dp[3].first), max(dp[1].second, dp[3].second) };
        }
        else {
            nx[1] = { min(dp[0].first,dp[2].first) + 1, max(dp[0].second,dp[2].second) + 1 };
            nx[3] = { dp[1].first + 1, dp[1].second + 1 };
            nx[0] = dp[2];
            nx[2] = { min(dp[1].first,dp[3].first), max(dp[1].second, dp[3].second) };
        }
        dp = nx;
    }

    int N = s.length();
    for (int i = 0; i < 4; i++) {
        if (dp[i].first <= N / 2 && dp[i].second >= N / 2) {
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;



}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}