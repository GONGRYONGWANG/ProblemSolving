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

int DP[100000];

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    vector<pii> arr(N + 1);
    arr[0] = { 0,0 };
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i < K; i++) DP[i] = -1;
    DP[0] = 0;


    int mx = 0;
    int idx = 0;

    for (int i = 1; i <= N; i++) {
        int x = arr[i].first;
        for (int j = K - 1; j >= 0; j--) {
            if (DP[j] == -1) continue;
            if (j + x > mx) {
                mx = j + x;
                idx = i;
            }
            if (j + x < K && DP[j + x] == -1) DP[j + x] = i;
        }
            
    }

    int ans = mx;

    stack<int> st;
    while (mx != 0) {
        st.push(arr[idx].second);
        mx -= arr[idx].first;
        idx = DP[mx];
    }

    cout << st.size() << " " << ans << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }


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