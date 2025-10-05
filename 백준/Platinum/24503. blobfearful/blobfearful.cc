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

bool isnprime[32000000];

void solve(int tc) {

    ll K, Q;
    cin >> K >> Q;
    vector<pll> arr;

    ll sqrtK = sqrt(K);

    for (ll i = 2; i <= sqrtK; i++) {
        if (isnprime[i]) continue;
        if (K % i == 0) {
            arr.push_back({ i,0 });
            while (K % i == 0) {
                K /= i;
                arr.back().second += 1;
            }
        }
        for (ll j = i * i; j <= sqrtK; j += i) isnprime[j] = true;
    }

    if (K != 1) {
        arr.push_back({ K,1 });
    }


    vector<vector<int>> v;

    for (auto& [p, c] : arr) {
        v.push_back({0});
        int x = 0;
        for (int i = 1; i <= c; i++) {
            if (x >= i) v.back().push_back(v.back().back());
            else {
                v.back().push_back(v.back().back() + 1);
                ll tmp = v.back().back();
                x += 1;
                while (tmp == tmp / p * p) {
                    x += 1;
                    tmp /= p;
                }
            }
        }
    }

    while (Q--) {
        ll A;
        cin >> A;

        ll ans = 1;
        for (int i = 0; i < arr.size(); i++) {
            auto [p, c] = arr[i];

            while (A == A / p * p && c > 0) {
                c -= 1;
                A /= p;
            }

            if (c > 0) ans = max(ans, p * v[i][c]);

        }

        cout << ans << " ";

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