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

pll DP[(1 << 23)];

void solve(int tc) {

    int N;
    cin >> N;
    vector<ll> arr(N);
    for (ll& x : arr) cin >> x;
    for (int i = N - 1; i > 0; i--) arr[i] -= arr[i - 1];
    DP[0] = { 0,0 };
    for (int bit = 1; bit < (1 << N); bit++) {
        DP[bit] = { inf,0 };
        for (int i = 0; i < N; i++) {
            if (!(bit & (1 << i))) continue;
            pll ret = { DP[bit ^ (1 << i)].first + 1,DP[bit ^ (1 << i)].second + arr[i] };
            if (ret.second == 0) ret.first -= 1;
            if (ret.first <= DP[bit].first) DP[bit] = ret;
        }
    }

    cout << DP[(1 << N) - 1].first;


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