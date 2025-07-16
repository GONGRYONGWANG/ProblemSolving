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


void solve(int tc) {

    ll A, B, N;
    cin >> A >> B >> N;
    if (N == 1) {
        cout << B - A + 1;
        return;
    }

    vector<ll> arr(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());

    ll sum = 0;
    for (int i = 0; i < N - 1; i++) {
        if (i % 2) sum -= arr[i];
        else sum += arr[i];
    }

    vector<pll> ret;

    ll l, r;
    if ((N - 1) % 2) {
        l = max(1ll, sum - B);
        r = min(arr[N - 2], sum - A);
    }
    else {
        l = max(1ll, A - sum);
        r = min(arr[N - 2], B - sum);
    }
    if (l <= r) ret.push_back({ l,r });

    for (int i = N - 2; i >= 0; i--) {
        if (i % 2) sum += arr[i] * 2;
        else sum -= arr[i] * 2;

        if (i % 2) {
            l = max(arr[i], sum - B);
            r = sum - A;
            if (i != 0) r = min(r, arr[i - 1]);
        }
        else {
            l = max(arr[i], A - sum);
            r = B - sum;
            if (i != 0) r = min(r, arr[i - 1]);
        }
        if (l > r) continue;
        ret.push_back({ l,r });
    }

    ll ans = 0;
    ll e = 0;
    for (auto [l, r] : ret) {
        ans += r - max(e, l - 1);
        e = r;
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