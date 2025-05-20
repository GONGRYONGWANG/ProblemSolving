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




void solve(int tc) {


    int N, M, C, D;
    cin >> N >> M >> C >> D;

    vector<int> dp(M + 1, 0);

    while (N--) {
        int b;
        cin >> b;

        vector<int> nx(M + 1);

        for (int i = 1; i <= C; i++) {
            multiset<int> st;

            for (int j = i; j <= min(M, i + D); j += C) st.insert(dp[j]);
            nx[i] = *st.rbegin() + (M - abs(b - i));

            for (int k = i + C; k <= M; k += C) {
                if (k - D - C >= 1) st.erase(st.find(dp[k - D - C]));
                if (k + D <= M) st.insert(dp[k + D]);
                nx[k] = *st.rbegin() + (M - abs(b - k));
            }
        }

        dp = nx;
    }
    
    int ans = 0;
    for (int i = 1; i <= M; i++) ans = max(ans, dp[i]);

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