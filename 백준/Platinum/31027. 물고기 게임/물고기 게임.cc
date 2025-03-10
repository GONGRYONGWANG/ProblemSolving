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


ll psum[500001][2];

void solve(int tc) {
    int N;
    cin >> N;

    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> psum[i][j];
            psum[i][j] += psum[i - 1][j];
        }
    }


    ll total = psum[N][0] + psum[N][1];

    if (N % 2) {
        ll A = psum[N / 2][0] + psum[N / 2][1];
        ll B = psum[N][0];
        if (A >= B) {
            cout << A << " " << total - A;
            return;
        }

        ll C = psum[N / 2 + 1][0] + psum[N / 2 + 1][1];
        cout << min(B, C) << " " << total - min(B, C);
        return;
    }

    ll A = psum[N / 2][0] + psum[N / 2][1];
    ll B = psum[N][0];
    ll C = psum[N / 2 + 1][0] + psum[N / 2 + 1][1];
    if (A >= B) {
        cout << A << " " << total - A;
        return;
    }
    cout << min(B, C) << " " << total - min(B, C);





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