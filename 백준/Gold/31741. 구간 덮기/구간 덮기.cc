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

    int N, s, e;
    cin >> N >> s >> e;

    vector<int> L;
    vector<int> R;
    vector<pii> M;

    vector<pii> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    for (auto [a, b] : arr) {
        if (a <= s && b >= e) {
            cout << 0;
            return;
        }

        if (a <= s) L.push_back(b);
        else if (b >= e) R.push_back(a);
        else M.push_back({ a,b });
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int ans = inf;

    for (int l : L) {
        auto it = upper_bound(R.begin(), R.end(), l);
        if (it == R.begin()) continue;
        it = prev(it);
        ans = min(ans, l - *it);
    }
    
    for (auto [a, b] : M) {
        int ret = 0;
        auto it = lower_bound(L.begin(), L.end(), a);
        if (it == L.end()) continue;
        ret += *it - a;
        it = upper_bound(R.begin(), R.end(), b);
        if (it == R.begin()) continue;
        it = prev(it);
        ret += b - *it;
        ans = min(ans, ret);
    }

    if (ans == inf) cout << -1;
    else cout << ans;


    








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