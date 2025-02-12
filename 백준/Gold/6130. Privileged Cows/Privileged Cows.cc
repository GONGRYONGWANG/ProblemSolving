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
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> cnt(4, 0);
    for (int& x : arr) {
        cin >> x;
        cnt[x] += 1;
    }

    int n = N;
    int _12 = 0, _13 = 0, _21 = 0, _23 = 0, _31 = 0, _32 = 0;
    for (int i = 0; i < cnt[1]; i++) {
        if (arr[i] == 2) _12 += 1;
        else if (arr[i] == 3) _13 += 1;
        else n -= 1;
    }
    for (int i = cnt[1]; i < cnt[1] + cnt[2]; i++) {
        if (arr[i] == 1) _21 += 1;
        else if (arr[i] == 3) _23 += 1;
        else n -= 1;
    }
    for (int i = cnt[1] + cnt[2]; i < N; i++) {
        if (arr[i] == 1) _31 += 1;
        else if (arr[i] == 2) _32 += 1;
        else n -= 1;
    }

    int ans = min(_12, _21) + min(_23, _32) + min(_31, _13);
    n -= 2 * ans;
    ans += n / 3 * 2;
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