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
#define INF ll(4e18)
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
///////////////////////////////////////////////////////////////



void solve(int tc) {


    int N;
    cin >> N;
    vector<ll> arr(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    ll D;
    cin >> D;

    if (N == 1) {
        if (arr[0] <= D) cout << 3;
        else cout << 1;
        return;
    }

    vector<ll> L = { 0 };
    for (int i = 0; i < N / 2; i++) {
        vector<ll> a = L;
        vector<ll> b = L;
        for (ll& x : a) x -= arr[i];
        for (ll& x : b) x += arr[i];

        ll n = L.size();
        vector<ll> ret(3 * n);
        int idx = 0;
        int idx1 = 0, idx2 = 0, idx3 = 0;

        while (idx != 3 * n) {
            ll mn = INF;
            if (idx1 != n) mn = min(L[idx1], mn);
            if (idx2 != n) mn = min(a[idx2], mn);
            if (idx3 != n) mn = min(b[idx3], mn);
            if (idx1 != n && mn == L[idx1]) {
                ret[idx] = L[idx1]; idx1++;
            }
            else if (idx2 != n && mn == a[idx2]) {
                ret[idx] = a[idx2]; idx2++;
            }
            else {
                ret[idx] = b[idx3]; idx3++;
            }
            idx++;
        }
        L = ret;
    }

    vector<ll> R = { 0 };
    for (int i = N / 2; i < N; i++) {
        vector<ll> a = R;
        vector<ll> b = R;
        for (ll& x : a) x -= arr[i];
        for (ll& x : b) x += arr[i];

        ll n = R.size();
        vector<ll> ret(3 * n);
        int idx = 0;
        int idx1 = 0, idx2 = 0, idx3 = 0;

        while (idx1 != n || idx2 != n || idx3 != n) {
            ll mn = INF;
            if (idx1 != n) mn = min(R[idx1], mn);
            if (idx2 != n) mn = min(a[idx2], mn);
            if (idx3 != n) mn = min(b[idx3], mn);
            if (idx1 != n && mn == R[idx1]) {
                ret[idx] = R[idx1]; idx1++;
            }
            else if (idx2 != n && mn == a[idx2]) {
                ret[idx] = a[idx2]; idx2++;
            }
            else {
                ret[idx] = b[idx3]; idx3++;
            }
            idx++;
        }
        R = ret;
    }

    reverse(R.begin(), R.end());

    ll ans = 0;

    int lidx = 0; int ridx = 0;
    for (ll x : L) {
        while (ridx != R.size() && R[ridx] >= -D - x) ridx += 1;
        while (lidx != R.size() && R[lidx] > D - x) lidx += 1;
        ans += ridx - lidx;
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