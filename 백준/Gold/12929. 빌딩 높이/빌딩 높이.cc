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
#define INF 1e18+7
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

    ll N, K;
    cin >> N >> K;
    ll M;
    cin >> M;

    vector<pll> arr(M + 2);
    arr[0] = { 0,0 };
    arr[M + 1] = { N - 1,INF };
    for (int i = 1; i <= M; i++) {
        cin >> arr[i].first;
        arr[i].first -= 1;
    }
    for (int i = 1; i <= M; i++) cin >> arr[i].second;

    ll ans = 0;

    multiset<ll> L, R;
    for (int i = 0; i <= M + 1; i++) {
        auto [x, t] = arr[i];
        R.insert(t + K * x);
    }
    for (int i = 0; i <= M; i++) {
        auto [x, t] = arr[i];
        L.insert(t - K * x);
        R.erase(R.find(t + K * x));

        ll l = *L.begin();
        ll r = *R.begin();

        ll p1 = (r - l) / (2 * K);
        ll p2 = p1 + 1;
        ll p3 = x;
        ll p4 = arr[i + 1].first;

        if (x <= p1 && p1 <= p4) {
            ans = max(ans, min(l + K * p1, r - K * p1));
        }
        if (x <= p2 && p2 <= p4) {
            ans = max(ans, min(l + K * p2, r - K * p2));
        }
        if (x <= p3 && p3 <= p4) {
            ans = max(ans, min(l + K * p3, r - K * p3));
        }
        if (x <= p4 && p4 <= p4) {
            ans = max(ans, min(l + K * p4, r - K * p4));
        }
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