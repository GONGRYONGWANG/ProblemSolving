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
#include<chrono>
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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


void solve(int tc) {

    int N, K;
    cin >> N >> K;

    vector<int> X(K);

    vector<tuple<int, int, int>> arr(K);
    for (int i = 0; i < K; i++) {
        ll x, r, c;
        cin >> x >> r >> c;
        X[i] = x;
        arr[i] = { x,r,c };
    }

    sort(X.begin(), X.end());

    for (auto& [x, r, c] : arr) {
        int L = lower_bound(X.begin(), X.end(), x - r) - X.begin();
        int R = prev(upper_bound(X.begin(), X.end(), x + r)) - X.begin();
        x = L; r = R;
    }

    sort(arr.begin(), arr.end());

    map<int, int> m;
    m[-1] = 0;
    for (auto [l, r, c] : arr) {
        auto it = m.lower_bound(l - 1);
        if (!m.count(r)) m[r] = inf;
        m[r] = min(m[r], it->second + c);
        it = m.find(r);
        while (prev(it)->second >= it->second) m.erase(prev(it));
        if (next(it) != m.end() && it->second >= next(it)->second) m.erase(it);
    }

    cout << m[K - 1];




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