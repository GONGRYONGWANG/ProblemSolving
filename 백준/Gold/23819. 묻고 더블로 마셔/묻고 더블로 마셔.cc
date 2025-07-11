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
vector<vector<ll>> matmul(const vector<vector<ll>>& a, const vector<vector<ll>>& b, ll mod = 0) { // 행렬 곱
    assert(a[0].size() == b.size());
    vector<vector<ll>> ret(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                ret[i][j] += a[i][k] * b[k][j];
                if (mod) ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

vector<vector<ll>> powmat(const vector<vector<ll>>& mat, ll n, ll mod = 0) { // 행렬 거듭제곱
    if (n == 1) return mat;
    if (n % 2) {
        return matmul(powmat(mat, n - 1, mod), mat, mod);
    }
    vector<vector<ll>> half = powmat(mat, n / 2, mod);
    return matmul(half, half, mod);
}

///////////////////////////////////////////////////////////////

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    

    vector<vector<ll>> init(1, vector<ll>(K));
    for (int i = 0; i < K; i++) {
        cin >> init[0][i];
    }

    ll P;
    cin >> P;

    vector<vector<ll>> mat(K, vector<ll>(K));
    for (int i = 0; i < K - 1; i++) {
        mat[i + 1][i] = 1;
    }
    for (int j = 0; j < K; j++) {
        mat[j][K - 1] = 1;
    }

    vector<vector<ll>> ret = matmul(init, powmat(mat, N - K, P), P);
    
    cout << ret[0][K - 1];






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