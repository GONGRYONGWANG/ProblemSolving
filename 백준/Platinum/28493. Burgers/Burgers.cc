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

    int N;
    cin >> N;
    vector<ll> x(N), a(N), b(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    ll l = 0;
    ll r = inf;
    while (r - l >= 3) {
        ll m1 = (l * 2 + r) / 3;
        ll m2 = (l + r * 2) / 3;

        ll ret1 = INF;
        ll ret2 = INF;
        for (int i = 0; i < N; i++) {
            if (a[i] * m1 > x[i]) ret1 = -INF;
            else ret1 = min(ret1, (x[i] - a[i] * m1) / b[i] + m1);
            if (a[i] * m2 > x[i]) ret2 = -INF;
            else ret2 = min(ret2, (x[i] - a[i] * m2) / b[i] + m2);
        }

        if (ret1 >= ret2) r = m2;
        else l = m1;

    }

    ll ans = 0;
    for (ll i = l; i <= r; i++) {
        ll ret = INF;
        for (int j = 0; j < N; j++) {
            ret = min(ret, (x[j] - a[j] * i) / b[j] + i);
        }
        ans = max(ans, ret);
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