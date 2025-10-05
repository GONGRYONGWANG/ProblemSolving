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
#include<chrono>
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
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

void solve(int tc) {

    ll L, C, S;
    ld c;
    cin >> L >> c >> S;
    C = c * 1e9;

    ll E, M;
    cin >> E >> M;

    ll mn, mx;
    ld _mn, _mx;
    cin >> _mx >> _mn;
    mn = _mn * 1e9; mx = _mx * 1e9;

    ll K = S / M;

    ll Cf = C; ll lf = L;
    for (int i = 0; i < K; i++) {
        Cf = Cf * lf / (lf + M);
        lf += M;
    }


    if (Cf > mx) {
        cout << 0;
        return;
    }

    if (Cf >= mn) {
        cout << L + S;
        return;
    }

    ll sc = C; ll sl = L;
    ll ans = 0;
    for (int i = 0; i <= K; i++) {

        ll l, c;
        l = sl; c = sc;

        ll ret = 0;
        int cnt = 0;
        while (c <= mx && c >= mn && cnt + i < K) {
            ret += min(E, l);
            cnt += 1;
            c = c * (l - min(E, l)) / (l - min(E, l) + M);
            l = l - min(E, l) + M;
        }

        ans = max(ans, ret);

        sc = sc * sl / (sl + M);
        sl += M;

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