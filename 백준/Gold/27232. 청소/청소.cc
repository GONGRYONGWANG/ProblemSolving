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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


void solve(int tc) {

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int& x : arr) cin >> x;

    map<int, int> m;
    for (int i = 0; i < K; i++) m[arr[i]] = i;

    ll ret = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it != m.begin()) {
            ret += abs(it->second - prev(it)->second);
        }
    }

    ll ans = ret;

    for (int i = K; i < N; i++) {
        auto it = m.find(arr[i - K]);
        if (it != m.begin()) ret -= abs(it->second - prev(it)->second);
        if (next(it) != m.end()) ret -= abs(it->second - next(it)->second);
        if (it != m.begin() && next(it) != m.end()) ret += abs(prev(it)->second - next(it)->second);
        m.erase(it);
        m[arr[i]] = i;
        it = m.find(arr[i]);
        if (it != m.begin() && next(it) != m.end()) ret -= abs(prev(it)->second - next(it)->second);
        if (it != m.begin()) ret += abs(it->second - prev(it)->second);
        if (next(it) != m.end()) ret += abs(it->second - next(it)->second);
        ans = min(ans, ret);
    }

    cout << ans;




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}