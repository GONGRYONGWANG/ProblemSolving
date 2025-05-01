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

string s;
int DP[1500][1500][5][3];
//1: left 0, 2: left 1, 3: right 0, 4: right 1
bool dp(int l, int r, int con, int q) {
    if (r < l) {
        if (con == 0) return false;
        else return true;
    }
    if (DP[l][r][con][q] != -1) return DP[l][r][con][q];

    bool ret = false;

    if (con == 0) {
        if (q == 2) {
            ret |= !dp(l, r, 0, 0);
            ret |= !dp(l, r, 0, 1);
        }
        if (s[l] == '0' || (s[l] == '?' && q == 0)) ret |= dp(l + 1, r, 1, q);
        if (s[l] == '1' || (s[l] == '?' && q == 1)) ret |= dp(l + 1, r, 2, q);
        if (s[r] == '0' || (s[r] == '?' && q == 0)) ret |= dp(l, r - 1, 3, q);
        if (s[r] == '1' || (s[r] == '?' && q == 1)) ret |= dp(l, r - 1, 4, q);

        return DP[l][r][con][q] = ret;
    }

    ret |= !dp(l, r, 0, q);

    if (con == 1 && (s[l] == '0' || (s[l] == '?' && q == 0))) ret |= dp(l + 1, r, 1, q);
    if (con == 2 && (s[l] == '1' || (s[l] == '?' && q == 1))) ret |= dp(l + 1, r, 2, q);
    if (con == 3 && (s[r] == '0' || (s[r] == '?' && q == 0))) ret |= dp(l, r - 1, 3, q);
    if (con == 4 && (s[r] == '1' || (s[r] == '?' && q == 1))) ret |= dp(l, r - 1, 4, q);

    return DP[l][r][con][q] = ret;
}

void solve(int tc) {
    
    cin >> s;

    bool flag = false;
    for (char x : s) {
        if (x == '?') flag = true;
    }

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            for (int con = 0; con < 5; con++) {
                for (int q = 0; q < 3; q++) {
                    DP[i][j][con][q] = -1;
                }
            }
        }
    }

    if (flag) cout << dp(0, s.length() - 1, 0, 2);
    else cout << dp(0, s.length() - 1, 0, 0);


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