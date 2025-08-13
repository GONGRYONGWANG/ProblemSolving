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


ll mod = 1e9 + 7;
ll comb[2001][1001];

int A[1001];
int L[1001]; int R[1001];

vector<int> v;

void dfs(int x) {
    if (x == -1) return;
    dfs(L[x]);
    v.push_back(A[x]);
    dfs(R[x]);
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int n = 0; n <= M; n++) {
        comb[n][0] = 1;
        for (int r = 1; r <= min(n, N); r++) {
            comb[n][r] = (comb[n - 1][r] + comb[n - 1][r - 1]) % mod;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> L[i] >> R[i];
    }

    v.push_back(0);
    dfs(1);
    v.push_back(M + 1);


    ll ans = 1;
    int cnt = 0;
    int prv = -1;
    for (int x : v) {
        if (x == -1) cnt += 1;
        else {
            ans = ans * comb[x - prv - 1][cnt] % mod;
            prv = x; cnt = 0;
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