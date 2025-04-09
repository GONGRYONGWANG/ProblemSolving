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
#define INF ll(1e18+7)
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
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
///////////////////////////////////////////////////////////////


void solve(int tc) {

    ll N;
    cin >> N;

    ll x0 = 0; ll y0 = 0;
    ll xy0 = 0;

    ll ans = 0;

    unordered_map<pii, ll, PiiHasher> m;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            xy0 += 1;
            continue;
        }
        if (x == 0) {
            x0 += 1;
            continue;
        }
        if (y == 0) {
            y0 += 1;
            continue;
        }

        int g = gcd(abs(x), abs(y));
        x /= g; y /= g;

        if (y < 0) {
            x = -x; y = -y;
        }

        if (m.count({ y,-x })) ans += m[{y, -x}];
        if (x < 0) {
            x = -x; y = -y;
        }
        m[{x, y}] += 1;
    }

    ans += x0 * y0;
    ans += xy0 * (N - xy0) + xy0 * (xy0 - 1) / 2;
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