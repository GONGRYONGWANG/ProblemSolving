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
#define INF ll(2e18)
const int inf = 1000000007;
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

gp_hash_table<int, pll> DP[3000];
int arr[3000];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    ll ans = 0;
    ll mod = 1e9 + 7;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int d = arr[i] - arr[j];
            DP[i][d] = { 1,2 };
            for (int k = d - 1; k <= d + 1; k++) {
                if (DP[j].find(k)==DP[j].end()) continue;
                ans += DP[j][k].first + DP[j][k].second;
                ans %= mod;
                DP[i][d].second += DP[j][k].first + DP[j][k].second;
                DP[i][d].second %= mod;
                DP[i][d].first += DP[j][k].first;
                DP[i][d].first %= mod;
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