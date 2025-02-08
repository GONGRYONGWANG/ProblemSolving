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

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    vector<ll> arr(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    vector<ll> s(K);
    for (ll& x : s) cin >> x;
    reverse(s.begin(), s.end());

    vector<int> DP(N + 1);
    for (int i = 1; i <= N; i++) DP[i] = inf;
    DP[1] = N;


    for (ll x : s) {
        vector<int> nDP = DP;
        for (int l = 1; l <= N; l++) {
            int r = DP[l];
            if (r == inf) continue;

            int nl = upper_bound(arr.begin(), arr.end(), arr[l - 1] + x) - arr.begin();
            if (r <= nl) {
                cout << "Yes";
                return;
            }
            nDP[nl] = min(nDP[nl], r);
            
            int nr = lower_bound(arr.begin(), arr.end(), arr[r] - x) - arr.begin();
            if (nr <= l) {
                cout << "Yes";
                return;
            }

            nDP[l] = min(nDP[l], nr);

        }
        DP = nDP;
    }

    cout << "No";



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