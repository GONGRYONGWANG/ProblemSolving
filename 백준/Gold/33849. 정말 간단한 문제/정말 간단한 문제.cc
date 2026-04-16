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

    int N;
    cin >> N;
    vector<ll> X(N + 1, 0);
    vector<ll> Y(N + 1, 0);

    for (int i = 1; i <= N; i++) cin >> X[i];
    for (int i = 1; i <= N; i++) cin >> Y[i];

    int idx = 1;
    for (int i = 1; i <= N; i++) {
        ll x1 = X[idx]; ll y1 = Y[idx];
        ll x2 = X[i]; ll y2 = Y[i];
        if (y2 * x1 > y1 * x2) idx = i;
    }

    int ans = 0;
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (X[idx] * Y[i] == X[i] * Y[idx]) ret += 1;
        else ret = 0;
        ans = max(ans, ret);
    }
    cout << Y[idx] / gcd(X[idx], Y[idx]) << " " << X[idx] / gcd(X[idx], Y[idx]) << endl;
    cout << ans;


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