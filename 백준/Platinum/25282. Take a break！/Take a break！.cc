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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
int N;
vector<ll> arr;
ll get(int k) {
    ll ret = 3600ll * (k - 1);
    int cnt = 0;
    int lv = 1;
    for (int i = 0; i < N; i++) {
        if (ret >= INF / 2) return INF;
        ret += arr[i] * lv;
        cnt += 1;
        if (cnt == k) {
            cnt = 0;
            lv *= 2;
        }
    }
    return ret;

}



void solve(int tc) {

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());

    int l = 1;
    int r = N;
    while (l + 2 < r) {
        int m1 = (2 * l + r) / 3;
        int m2 = (l + 2 * r) / 3;
        ll g1 = get(m1); ll g2 = get(m2);
        if (g2 == INF) l = m2 + 1;
        else if (get(m1) <= get(m2)) r = m2;
        else l = m1;
    }

    ll ans = INF;
    for (int i = l; i <= r; i++) {
        ans = min(ans, get(i));
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