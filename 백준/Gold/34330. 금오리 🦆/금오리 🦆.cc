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


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


void solve(int tc) {
   
    ll R, L;
    cin >> R >> L;
    int N, M;
    cin >> N >> M;

    queue<int> q;
    vector<bool> visited(N, false);
    vector<tuple<ll,ll,ll>> lotus(N);
    for (int i = 0; i < N; i++) {
        ll x, y, r;
        cin >> x >> y >> r;
        lotus[i] = { x,y,r };
        if (r >= R || x * x + y * y >= (R - r) * (R - r)) {
            visited[i] = true;
            q.push(i);
        }
    }

    auto connected = [](tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) {
        auto [x1, y1, r1] = a;
        auto [x2, y2, r2] = b;
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
    };

    while (!q.empty()) {
        int l = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (connected(lotus[l], lotus[i])) {
                visited[i] = true;
                q.push(i);
            }
        }
    }


    int ans = 0;

    while (M--) {
        ll a, b;
        cin >> a >> b;
        int ret = (L >= R);
        if (a * a + b * b >= (R - L) * (R - L)) ret = 1;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) continue;
            if (connected(lotus[i], { a,b,L })) ret = 1;
        }
        ans += ret;
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