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

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> arr(N + 2, 0);
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = N; i >= 0; i--) arr[i] += arr[i + 1];

    vector<pii> W(K + 1);
    for (int i = 0; i < K; i++) cin >> W[i].first;
    W[K] = { N + 1, 0 };
    
    for (int i = K - 1; i >= 0; i--) {
        W[i].second = arr[W[i].first] - arr[W[i + 1].first];
    }
    
    

    auto cmp = [](pii& a, pii& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    };

    sort(W.begin(), W.end(), cmp);

    vector<int> ans(M);

    for (int i = 0; i < M; i++) ans[i] = W[i].first;

    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << endl;





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