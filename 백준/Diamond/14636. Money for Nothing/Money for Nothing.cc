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
#define INF ll(4e18+7)
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

vector<pll> A, B;

ll ans = 0;
void dnc(int s, int e, int l, int r) {
    if (e < s) return;
    int m = (s + e) / 2;
    ll mxval = -2e18; int mxidx = l;
    for (int i = l; i <= r; i++) {
        ll dx = B[i].first - A[m].first;
        ll dy = B[i].second - A[m].second;
        if ((dx >= 0 || dy >= 0) && dx * dy >= mxval) {
            mxval = dx * dy;
            mxidx = i;
        }
    }
    ans = max(ans, mxval);
    dnc(s, m - 1, l, mxidx); dnc(m + 1, e, mxidx, r);
}

void solve(int tc) {

    int M, N;
    cin >> M >> N;

    vector<pll> a(M);
    for (int i = 0; i < M; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    for (int i = 0; i < M; i++) {
        if (A.empty() || A.back().second > a[i].second) A.push_back(a[i]);
    }

    vector<pll> b(N);
    for (int i = 0; i < N; i++) cin >> b[i].first >> b[i].second;
    sort(b.begin(), b.end());
    for (int i = 0; i < N; i++) {
        while (!B.empty() && B.back().second <= b[i].second) B.pop_back();
        B.push_back(b[i]);
    }

    dnc(0, A.size() - 1, 0, B.size() - 1);
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