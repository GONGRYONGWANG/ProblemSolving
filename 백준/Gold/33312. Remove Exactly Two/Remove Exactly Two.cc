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


void solve(int tc) {

    int N;
    cin >> N;
    vector<unordered_set<int>> E(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].insert(v); E[v].insert(u);
    }

    if (N == 2) {
        cout << 0 << endl;
        return;
    }

    vector<pii> arr;
    for (int i = 1; i <= N; i++) {
        arr.push_back({ E[i].size(),i });
    }
    sort(arr.rbegin(), arr.rend());

    if (arr[0].first == arr[2].first) {
        cout << arr[0].first + arr[0].first - 1 << endl;
        return;
    }

    int ans = 0;

    if (arr[0].first != arr[1].first) {
        for (int i = 1; i < N; i++) {
            int ret = arr[0].first + arr[i].first - 1;
            if (E[arr[0].second].count(arr[i].second)) ret -= 1;
            ans = max(ans, ret);
        }
        cout << ans << endl;
        return;
    }

    ans = arr[0].first + arr[1].first - 1;
    if (E[arr[0].second].count(arr[1].second)) ans -= 1;
    for (int i = 2; i < N; i++) {
        int ret = arr[0].first + arr[i].first - 1;
        if (E[arr[0].second].count(arr[i].second)) ret -= 1;
        ans = max(ans, ret);
        ret = arr[1].first + arr[i].first - 1;
        if (E[arr[1].second].count(arr[i].second)) ret -= 1;
        ans = max(ans, ret);
    }

    cout << ans << endl;


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}