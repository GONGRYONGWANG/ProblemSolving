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


int W[1001], T[1001];
int nx[1001];
bool start[1001];

int DP[100001];

void solve(int tc) {

    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) cin >> W[i];
    for (int i = 1; i <= N; i++) cin >> T[i];
    
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        nx[p] = i;
        if (p == 0) start[i] = true;
    }

    for (int i = 1; i <= S; i++) DP[i] = inf;


    for (int i = 1; i <= N; i++) {
        if (!start[i]) continue;

        vector<pii> v;
        int w = 0, t = 0;
        int x = i;
        while (x) {
            w += W[x];
            t += T[x];
            v.push_back({ w,t });
            x = nx[x];
        }

        for (int j = S - 1; j >= 0; j--) {
            for (auto [w,t] : v) {
                DP[min(S, j + w)] = min(DP[min(S, j + w)], DP[j] + t);
            }
        }

    }

    if (DP[S] == inf) cout << -1;
    else cout << DP[S];



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