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

    int N, K;
    cin >> N >> K;
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        int v, w;
        cin >> v >> w;
        arr[i] = { v,w,i + 1 };
    }

    ld l = 0;
    ld r = 1000000;
    while (l + 1e-10 < r) {
        ld m = (l + r) / 2;
        auto cmp = [&](vector<int>& a, vector<int>& b) {
            return a[0] - m * a[1] > b[0] - m * b[1];
        };
        sort(arr.begin(), arr.end(), cmp);
        int totalv = 0; int totalw = 0;
        for (int i = 0; i < K; i++) {
            totalv += arr[i][0]; totalw += arr[i][1];
        }
        if (totalv >= m * totalw) l = m;
        else r = m;
    }

    auto cmp = [&](vector<int>& a, vector<int>& b) {
        return a[0] - l * a[1] > b[0] - l * b[1];
    };

    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < K; i++) {
        cout << arr[i][2] << " ";
    }




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