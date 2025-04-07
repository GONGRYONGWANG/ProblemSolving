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
#define INF ll(1e18+7)
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

    ll M, N;
    cin >> M >> N;

    ll ret = 0;
    ll x = 0; ll y = 0;
    if (M >= N) {
        if (N % 2) {
            x += N / 2;
            y += N / 2;
            x += M - N / 2 * 2;
            y += 1;
            ret += N / 2 * 4;
            if (M != N) ret += 1;
        }
        else {
            x += (N - 2) / 2;
            y += (N - 2) / 2;
            x += 2; y += 1;
            ret += (N - 2) / 2 * 4;
            ret += 2;
            if (M != N) ret += 1;
        }
    }
    else {
        if (M % 2) {
            x += M / 2;
            y += M / 2;
            y += N - M / 2 * 2;
            x += 1;
            ret += M / 2 * 4;
        }
        else {
            x = M / 2 + 1;
            y += M / 2;
            ret = M / 2 * 4 - 2;
        }
    }


    cout << ret << endl;
    cout << x << " " << y;


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