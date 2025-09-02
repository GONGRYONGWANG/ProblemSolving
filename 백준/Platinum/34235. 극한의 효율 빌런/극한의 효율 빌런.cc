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

    ll N, K;
    cin >> N >> K;

    vector<pll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first = min(arr[i].first, K);
    }

    ll l = 1;
    ll r = 1e9;
    while (l < r) {
        ll m = (l + r) / 2;
        vector<ll> DP(K + 1, INF);
        DP[0] = 0;

        ll val = 0; ll ext = 0;
        for (auto& [v, c] : arr) {
            if (c <= m) {
                val += v;
                ext += m - c;
                continue;
            }
            for (int j = K - v; j >= 0; j--) {
                DP[j + v] = min(DP[j + v], DP[j] + c - m);
            }
        }

        for (int j = K - 1; j >= 0; j--) {
            DP[j] = min(DP[j], DP[j + 1]);
        }

        if (val >= K || ext >= DP[K - val])  r = m;
        else l = m + 1;
    }

    vector<ll> DP(K + 1, INF);
    DP[0] = 0;
    ll val = 0; ll ext = 0;
    for (auto& [v, c] : arr) {
        if (c <= l) {
            val += v;
            ext += l - c;
            continue;
        }
        for (int j = K - v; j >= 0; j--) {
            DP[j + v] = min(DP[j + v], DP[j] + c - l);
        }
    }

    for (int j = K - 1; j >= 0; j--) {
        DP[j] = min(DP[j], DP[j + 1]);
    }

    if (val >= K) {
        if (ext > 0) cout << l - 1;
        else cout << l;
    }
    else if (ext == DP[K - val]) cout << l;
    else cout << l - 1;

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