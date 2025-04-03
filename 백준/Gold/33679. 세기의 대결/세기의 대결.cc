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
#define INF 1e18+7
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
    vector<int> A(2 * N), B(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i + N] = A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i + N] = B[i];
    }
    
    int ret1 = 0;
    int ret2 = 0;
    for (int i = 0; i < N; i++) {
        vector<int> a, b;
        for (int j = i; j < i + N; j++) {
            auto it = lower_bound(a.begin(), a.end(), A[j]);
            if (it == a.end()) a.push_back(A[j]);
            else *it = A[j];
            it = lower_bound(b.begin(), b.end(), B[j]);
            if (it == b.end()) b.push_back(B[j]);
            else *it = B[j];
        }
        ret1 = max(ret1, int(a.size()));
        ret2 = max(ret2, int(b.size()));
    }

    if (ret1 > ret2) cout << "YJ Win!";
    else if (ret1 == ret2) cout << "Both Win!";
    else cout << "HG Win!";



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