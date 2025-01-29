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

    int N;
    cin >> N;
    vector<int> T(N);
    vector<int> F(N);

    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        while (K--) {
            int x; cin >> x;
            x -= 1;
            T[i] |= (1 << x);
        }
        int L; cin >> L;
        F[i] = (1 << N) - 1;
        while (L--) {
            int x; cin >> x;
            x -= 1;
            F[i] &= (1 << N) - 1 - (1 << x);
        }
    }

    for (int bit = 0; bit < (1 << N); bit++) {
        bool b = true;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                if ((bit | T[i]) != bit) b = false;
                if ((bit & F[i]) != bit) b = false;
            }
            else {
                if (((bit | T[i]) == bit) && ((bit & F[i]) == bit)) b = false;
            }
            if (!b) break;
        }
        if (b) {
            for (int i = 0; i < N; i++) {
                if (bit & (1 << i)) cout << "true";
                else cout << "false";
                cout << endl;
            }
            return;
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