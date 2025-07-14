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

bool cmp(vector<ll>& a, vector<ll>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

void solve(int tc) {

    int N;
    cin >> N;
    
    ll l = 0, r = 0;
    vector<vector<ll>> arr(N);
    for (int i = 0; i < N; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        l += a; r += b;
        arr[i] = { l,r,x };
    }

    sort(arr.begin(), arr.end(), cmp);

    ll ans = 0;
    map<ll, ll> m;
    m[0] = 0;
    for (int i = 0; i < N; i++) {
        ll l, r, x;
        l = arr[i][0]; r = arr[i][1]; x = arr[i][2];
        if (l > 0 || r < 0) continue;

        auto it = prev(m.upper_bound(r));
        m[r] = max(m[r], it->second + x);

        it = m.find(r);
        while (next(it) != m.end() && next(it)->second <= it->second) {
            m.erase(next(it));
        }

        ans = max(ans, it->second);

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