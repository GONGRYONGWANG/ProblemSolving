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

    map<int, int> m;
    map<int, int> m2;
    for (int i = 0; i < 100; i++) {
        m[i * i * i] = i * i * 6;
        m[i * i * (i + 1)] = 2 * (i * i + i * (i + 1) * 2);
        m[i * (i + 1) * (i + 1)] = 2 * (i * (i + 1) * 2 + (i + 1) * (i + 1));
        m2[i * (i + 1)] =  2 * (i + i + 1);
        m2[i * i] = 4 * i;
    }

    m[1000000] = 100 * 100 * 6;
    m2[100 * 100] = 100 * 100 + 100 * 4;

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        auto it = prev(m.upper_bound(N));
        N -= it->first;
        int ret = it->second;

        it = prev(m2.upper_bound(N));
        N -= it->first;
        ret += it->second;

        if (N != 0) ret += 2;

        cout << ret << endl;

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