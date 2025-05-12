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

    ll xtotal = 0;
    ll ytotal = 0;
    vector<pll> X(N);
    vector<pll> Y(N);
    for (int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;
        X[i - 1] = { x,i };
        Y[i - 1] = { y,i };
        xtotal += x;
        ytotal += y;
    }

    sort(X.begin(), X.end()), sort(Y.begin(), Y.end());

    vector<ll> ret(N + 1, 0);

    for (int i = 0; i < N; i++) {

        if (i != 0) ret[X[i].second] += X[i].first * i - X[i - 1].first;
        if (i == 0) ret[X[i].second] += xtotal - X[i].first - X[i].first * (N - i - 1);
        if (i != 0 && i != N - 1) ret[X[i].second] += xtotal - X[i].first - X[i - 1].first - X[i].first * (N - i - 1);
        if (i != 0) X[i].first += X[i - 1].first;

        if (i != 0) ret[Y[i].second] += Y[i].first * i - Y[i - 1].first;
        if (i == 0) ret[Y[i].second] += ytotal - Y[i].first - Y[i].first * (N - i - 1);
        if (i != 0 && i != N - 1) ret[Y[i].second] += ytotal - Y[i].first - Y[i - 1].first - Y[i].first * (N - i - 1);
        if (i != 0) Y[i].first += Y[i - 1].first;
    }

    int ans = 1;
    for (int i = 2; i <= N; i++) {
        if (ret[i] < ret[ans]) ans = i;
    }

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
