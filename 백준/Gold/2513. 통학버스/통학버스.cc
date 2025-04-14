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
#define INF ll(9e18)
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

    int N, K, S;
    cin >> N >> K >> S;;
    vector<pii> L, R;
    for (int i = 0; i < N; i++) {
        int x, n;
        cin >> x >> n;
        if (x < S) L.push_back({ x,n });
        else R.push_back({ x,n });
    }
    sort(L.begin(), L.end());
    sort(R.rbegin(), R.rend());

    int ans = 0;
    int cnt = 0;
    int d;
    for (auto [x, n] : L) {
        if (cnt == 0) d = S - x;
        if (cnt + n < K) {
            cnt += n;
            continue;
        }
        n -= (K - cnt);
        ans += d * 2;
        d = S - x;
        ans += n / K * d * 2;
        n %= K;
        cnt = n;
    }
    if (cnt != 0) ans += d * 2;


    cnt = 0;
    for (auto [x, n] : R) {
        if (cnt == 0) d = x - S;
        if (cnt + n < K) {
            cnt += n;
            continue;
        }
        n -= (K - cnt);
        ans += d * 2;
        d = x - S;
        ans += n / K * d * 2;
        n %= K;
        cnt = n;
    }
    if (cnt != 0) ans += d * 2;

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