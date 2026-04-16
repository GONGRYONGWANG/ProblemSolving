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
ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}
ll modinv(ll x, ll mod) { // when mod is primenum
    return powmod(x, mod - 2, mod);
}
///////////////////////////////////////////////////////////////

bool isnprime[5001];
vector<ll> prime;



void solve(int tc) {

    for (int i = 2; i <= 5000; i++) {
        if (isnprime[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j <= 5000; j += i) isnprime[j] = true;
    }




    int T;
    cin >> T;
    while (T--) {
        int _a, _b, _c, _d;
        cin >> _a >> _b >> _c >> _d;

        bool flag = true;

        for (int i = 0; i < 669; i++) {
            ll p = prime[i];
            ll cnt1 = 0; ll cnt2 = 0;

            int a = _a, b = _b, c = _c, d = _d;
            int e = a - b; int f = c - d;

            while (a) a /= p, cnt1 += a;
            while (b) b /= p, cnt1 -= b;
            while (e) e /= p, cnt1 -= e;

            while (c) c /= p, cnt2 += c;
            while (d) d /= p, cnt2 -= d;
            while (f) f /= p, cnt2 -= f;

            if (cnt1 != 0 && cnt2 != 0) {
                flag = false; 
                break;
            }
        }

        cout << flag << endl;

    }






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