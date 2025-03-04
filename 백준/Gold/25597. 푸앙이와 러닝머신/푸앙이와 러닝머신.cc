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
const ll INF = 1e18 + 7;
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

    int X, T;
    cin >> X >> T;
    int a = X / 8;
    X %= 8;
    int b = X / 4;
    X %= 4;
    int c = X;

    if (a + b + c > T) {
        cout << -1;
        return;
    }

    if (a * 2 + b + c <= T) {
        b += a * 2;
        a = 0;
    }
    if (a + b * 4 + c <= T) {
        c += b * 4;
        b = 0;
    }

    int n = 0;
    if (a != 0) n += 1;
    if (b != 0) n += 1;
    if (c != 0) n += 1;

    cout << n << endl;
    if (a != 0) {
        cout << T - a - b - c << " " << 8 << endl;
    }
    if (b != 0) {
        cout << T - b - c << " " << 4 << endl;
    }
    if (c != 0) {
        cout << T - c << " " << 1 << endl;
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