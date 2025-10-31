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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////



void solve(int tc) {

    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;

        ll total = 0;
        map<ll, ll> A, B;
        A[0] = 0;
        B[0] = 0;
        for (int i = 0; i < N / 2; i++) {
            ll x; cin >> x;
            total += x;
            vector<pll> v;
            for (auto it = A.begin(); it != A.end(); it++) {
                v.push_back({ it->first + x,it->second + x });
                v.push_back({ it->first - x,it->second });
            }
            for (auto& [a, b] : v) {
                A[a] = max(A[a], b);
            }
        }
        for (int i = N / 2; i < N; i++) {
            ll x; cin >> x;
            total += x;
            vector<pll> v;
            for (auto it = B.begin(); it != B.end(); it++) {
                v.push_back({ it->first + x,it->second + x });
                v.push_back({ it->first - x,it->second });
            }
            for (auto& [a, b] : v) {
                B[a] = max(B[a], b);
            }
        }

        ll ret = 0;
        for (auto& [a, b] : A) {
            if (!B.count(-a)) continue;
            ret = max(ret, b + B[-a]);
        }

        cout << total - ret * 2 << endl;

    }
       







    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}