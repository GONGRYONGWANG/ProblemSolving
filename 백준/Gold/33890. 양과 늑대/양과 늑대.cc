// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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

    int N, M, K;
    cin >> N >> M >> K;

    multiset<int> A, B;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        B.insert(x);
    }

    int ret = 0;

    int mna = 0, mnb = 0;

    while (!A.empty()) {
        int x = *A.rbegin();
        A.erase(prev(A.end()));
        if (A.empty() || *A.begin() + x > K) {
            mna = x;
            continue;
        }
        ret += 1;
        A.erase(prev(A.upper_bound(K - x)));
    }

    while (!B.empty()) {
        int x = *B.rbegin();
        B.erase(prev(B.end()));
        if (B.empty() || *B.begin() + x > K) {
            mnb = x;
            continue;
        }
        ret += 1;
        B.erase(prev(B.upper_bound(K - x)));
    }


    if (mna && mnb && mna + mnb <= K) ret += 1;

    cout << N + M - ret;

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