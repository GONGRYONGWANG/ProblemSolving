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
#define INF ll(2e18)
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
///////////////////////////////////////////////////////////////

ll get(ll a, ll b, ll c, ll d) {
    return max(max(a, b), max(c, d)) - min(min(a, b), min(c, d));
}

void solve(int tc) {

    int N;
    cin >> N;

    ll total = 0;
    map<ll, vector<pll>> X, Y;

    for (int i = 0; i < N; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        X[x].push_back({ y,w });
        Y[y].push_back({ x,w });
        total += w;
    }

    X[-inf].push_back({ 0,0 });

    ll ans = INF;

    ll psum = 0;
    for (auto iter = X.begin(); iter != X.end(); iter++) {
        for (pll& p : iter->second) psum += p.second;
        ll thres = iter->first;
        ll s2 = psum, s1 = total - psum, s3 = 0, s4 = 0;
        ans = min(ans, get(s1, s2, s3, s4));
        for (auto it = Y.begin(); it != Y.end(); it++) {
            for (auto [x, w] : it->second) {
                if (x <= thres) {
                    s2 -= w; s3 += w;
                }
                else {
                    s1 -= w;
                    s4 += w;
                }
            }
            ans = min(ans, get(s1, s2, s3, s4));
        }
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