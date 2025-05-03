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
#define INF ll(4e18)
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
///////////////////////////////////////////////////////////////



void solve(int tc) {

    int N;
    cin >> N;

    vector<pii> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first;
    for (int i = 0; i < N; i++) cin >> arr[i].second;

    int K;
    cin >> K;

    int init = 0;
    int M;
    cin >> M;
    while (M--) {
        int x;
        cin >> x;
        init += arr[x].first;
    }

    vector<pii> DP1, DP2;
    DP1.push_back({ 0,0 });
    DP2.push_back({ 0,0 });

    for (int i = 0; i < min(N, 16); i++) {
        for (int j = DP1.size() - 1; j >= 0; j--) {
            DP1.push_back({ DP1[j].first + arr[i].first, DP1[j].second + arr[i].second });
        }
    }

    for (int i = min(N, 16); i < N; i++) {
        for (int j = DP2.size() - 1; j >= 0; j--) {
            DP2.push_back({ DP2[j].first + arr[i].first, DP2[j].second + arr[i].second });
        }
    }

    sort(DP1.begin(), DP1.end());
    sort(DP2.begin(), DP2.end());

    vector<pii> dp1, dp2;
    dp1.push_back({ 0,0 });
    dp2.push_back({ 0,0 });

    for (pii p : DP1) {
        while (p.first == dp1.back().first && p.second > dp1.back().second) dp1.pop_back();
        if (p.second > dp1.back().second) dp1.push_back(p);
    }
    for (pii p : DP2) {
        while (p.first == dp2.back().first && p.second > dp2.back().second) dp2.pop_back();
        if (p.second > dp2.back().second) dp2.push_back(p);
    }

    dp2.push_back({ inf, inf });

    int ans = inf;

    int r = dp2.size() - 1;
    for (int i = 0; i < dp1.size(); i++) {
        while (r != 0 && dp1[i].second + dp2[r - 1].second >= K) {
            r -= 1;
        }
        ans = min(ans, dp1[i].first + dp2[r].first);
    }

    if (ans == inf) cout << -1;
    else cout << max(0, ans - init);

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