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

    if (N <= 10) {
        for (int i = 0; i < N; i++) cout << 'a';
        return;
    }

    ll mx = 0;
    ll idx = 0;

    for (int i = 0; i <= N - 11; i++) {
        ll ret = (i + 2) * (i + 1) / 2;
        for (int j = 0; j < (N - 11 - i) % 9; j++) {
            ret *= (N - 11 - i) / 9 + 2;
        }
        for (int j = (N - 11 - i) % 9; j < 9; j++) {
            ret *= (N - 11 - i) / 9 + 1;
        }

        if (ret > mx) idx = i;
        mx = max(mx, ret);
    }

    string s = "raithorse";

    for (int j = 0; j < 2; j++) {
        int n = (N - 11 - idx) / 9 + 1;
        if (j < (N - 11 - idx) % 9) n += 1;
        for (int i = 0; i < n; i++) cout << s[j];
    }

    for (int i = 0; i < idx + 2; i++) {
        cout << 'b';
    }
    for (int j = 2; j < 9; j++) {
        int n = (N - 11 - idx) / 9 + 1;
        if (j < (N - 11 - idx) % 9) n += 1;
        for (int i = 0; i < n; i++) cout << s[j];
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