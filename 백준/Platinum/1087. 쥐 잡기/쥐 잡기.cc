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

ld getT(pll a, pll b) {
    if (a.first > b.first) swap(a, b);
    auto [p1, v1] = a;
    auto [p2, v2] = b;
    if (v2 >= v1) return 0;
    return ld(p2 - p1) / (v1 - v2);
}

int N;
pll X[50];
pll Y[50];

ld cal(ld t) {
    ld mnx = INF; ld mxx = -INF;
    ld mny = INF; ld mxy = -INF;
    for (int i = 0; i < N; i++) {
        mnx = min(mnx, X[i].first + t * X[i].second);
        mxx = max(mxx, X[i].first + t * X[i].second);
        mny = min(mny, Y[i].first + t * Y[i].second);
        mxy = max(mxy, Y[i].first + t * Y[i].second);
    }
    return max(mxx - mnx, mxy - mny);
}

void solve(int tc) {

    cin >> N;

    for (int i = 0; i < N; i++) {
        ll px, py, vx, vy;
        cin >> px >> py >> vx >> vy;
        X[i] = { px,vx };
        Y[i] = { py,vy };
    }

    vector<ld> T = {0};

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            T.push_back(getT(X[i], X[j]));
            T.push_back(getT(Y[i], Y[j]));
        }
    }


    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());

    ld ans = cal(0);

    for (int i = 0; i < T.size() - 1; i++) {
        ld l = T[i]; ld r = T[i + 1];
        while (r - l > 1e-13) {
            ld m1 = (l * 2 + r) / 3;
            ld m2 = (l + r * 2) / 3;
            if (cal(m1) < cal(m2)) r = m2;  
            else l = m1;
        }
        ans = min(ans, cal(l));
    }

    cout << fixed;
    cout.precision(10);
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