// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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

ll A[1000001];
ll B[1000001];

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i + N] = A[i];
    }
    for (int i = 1; i <= 2 * N; i++) {
        A[i] += A[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        B[i + N] = B[i];
    }
    for (int i = 1; i <= 2 * N; i++) {
        B[i] += B[i - 1];
    }

    deque<int> q;
    for (int i = 1; i < N; i++) {
        while (!q.empty() && A[q.back()] <= A[i]) q.pop_back();
        q.push_back(i);
    }

    ll ans = -INF;

    for (int i = 1; i <= N; i++) {
        while (!q.empty() && A[q.back()] <= A[i + N - 1]) q.pop_back();
        q.push_back(i + N - 1);
        while (B[q.front()] - B[i - 1] < K) q.pop_front();
        ans = max(ans, A[q.front()] - A[i - 1]);
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