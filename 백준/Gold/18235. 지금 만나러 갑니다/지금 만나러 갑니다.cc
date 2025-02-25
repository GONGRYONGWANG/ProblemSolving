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

    int N;
    cin >> N;
    vector<bool> DP1(N + 1, false);
    vector<bool> DP2(N + 1, false);
    int A, B;
    cin >> A >> B;
    DP1[A] = true; DP2[B] = true;

    for (int i = 0; i < 19; i++) {
        vector<bool> nx1(N + 1, false);
        vector<bool> nx2(N + 1, false);
        for (int j = 1; j <= N; j++) {
            if (DP1[j]) {
                if (j - (1 << i) > 0) nx1[j - (1 << i)] = true;
                if (j + (1 << i) <= N) nx1[j + (1 << i)] = true;
            }
            if (DP2[j]) {
                if (j - (1 << i) > 0) nx2[j - (1 << i)] = true;
                if (j + (1 << i) <= N) nx2[j + (1 << i)] = true;
            }
        }

        for (int j = 1; j <= N; j++) {
            if (nx1[j] && nx2[j]) {
                cout << i + 1;
                return;
            }
        }

        DP1 = nx1; DP2 = nx2;


    }

    cout << -1;





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