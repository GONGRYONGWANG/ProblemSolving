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
#define all(x) (x).begin(), (x).end()


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

void solve(int tc) {
    while (1) {
        int N;
        cin >> N;
        if (N == 0) return;

        vector<pii> arr(N + 1);
        for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

        int x = 0;
        vector<int> DP(4, inf);
        DP[0] = 0;
        int prv = 0;

        for (int i = 1; i <= N; i++) {

            int p, t;
            p = arr[i].first; t = arr[i].second;
            vector<int> nx(4, inf);
            int dist = abs(x - p);
            for (int j = 0; j < 4; j++) {
                if (DP[j] == inf) continue;
                if (x * (1 + j) + p <= t - prv) nx[1] = min(nx[1], DP[j] + x + p);
                if (j == 3) continue;
                if (dist * (1 + j) > t - prv) continue;
                nx[j + 1] = min(nx[j + 1], DP[j] + dist);
            }

            bool b = false;
            for (int j = 0; j < 4; j++) {
                b |= (nx[j] != inf);
            }
            if (!b) {
                cout << "NG" << " " << i << endl;
                break;
            }

            int ans = inf;
            if (i == N) {
                for (int i = 0; i < 4; i++) ans = min(ans, nx[i] + p);
                cout << "OK" << " " << ans << endl;
            }

            x = p; prv = t; DP = nx;
        }

    }





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