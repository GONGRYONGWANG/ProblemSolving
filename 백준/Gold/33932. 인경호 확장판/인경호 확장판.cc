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

    ll N, R;
    cin >> N >> R;

    vector<pll> arr(N + 2);
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    arr[0] = arr[N]; arr[N + 1] = arr[1];

    int idx = 1;
    for (int i = 1; i <= N; i++) {
        auto [x1, y1] = arr[i - 1];
        auto [x2, y2] = arr[i + 1];
        auto [x3, y3] = arr[idx - 1];
        auto [x4, y4] = arr[idx + 1];
        if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4)) idx = i;
    }

    cout << idx << endl;

    ld a = arr[idx + 1].first - arr[idx - 1].first, b = arr[idx + 1].second - arr[idx - 1].second;

    cout << fixed;
    cout.precision(10);
    cout << ld(-b) / sqrt(a * a + b * b) * R + arr[idx].first << " " << ld(a) / sqrt(a * a + b * b) * R + arr[idx].second;




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