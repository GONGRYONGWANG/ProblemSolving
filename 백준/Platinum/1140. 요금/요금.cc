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

    ll T, K1, P1, K2, P2;
    cin >> T >> K1 >> P1 >> K2 >> P2;
    
    if (P1 >= K1 * 10 && P2 >= K2 * 10) {
        cout << T * 10;
        return;
    }

    if (P1 >= K1 * 10) {
        cout << min((T + K2 - 1) / K2 * P2, T / K2 * P2 + T % K2 * 10);
        return;
    }
    
    if (P2 >= K2 * 10) {
        cout << min((T + K1 - 1) / K1 * P1, T / K1 * P1 + T % K1 * 10);
        return;
    }


    if (K1 < K2) swap(K1, K2), swap(P1, P2);

    ll ans = T * 10;

    for (ll i = 0; i <= min(K2 - 1, (T + K1 - 1) / K1); i++) {
        ll ret = P1 * i;
        if (K1 * i >= T) {
            ans = min(ans, ret);
            continue;
        }

        ll val = T - K1 * i;

        if (__int128(P1) * __int128(K2) < __int128(P2) * __int128(K1)) { // __int128
            ll ret1 = ret + val / K2 / K1 * K2 * P1 + val / K2 % K1 * P2 + val % K2 * 10;
            ll ret2 = ret + (val + K2 - 1) / K2 / K1 * K2 * P1 + (val + K2 - 1) / K2 % K1 * P2;
            ans = min(ans, min(ret1, ret2));
        }
        else {
            ll ret1 = ret + val / K2 * P2 + val % K2 * 10;
            ll ret2 = ret + (val + K2 - 1) / K2 * P2;
            ans = min(ans, min(ret1, ret2));
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