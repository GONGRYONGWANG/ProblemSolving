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
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int DP[1001][2001];
bool bang[1001][2001];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a += 1000; b += 1000;
        for (int i = a + 1; i < b; i++) {
            bang[t][i] = true;
        }
    }

    deque<pii> q;
    DP[0][1000] = 1;
    q.push_back({ 0,1000 });
    while (!q.empty()) {
        auto [t, x] = q.front();
        q.pop_front();
        if (bang[t][x]) continue;
        if (t == 1000) {
            cout << DP[t][x] - 1;
            return;
        }
        if (x != 0 && !DP[t+1][x-1]) {
            DP[t + 1][x - 1] = DP[t][x] + 1;
            q.push_back({ t + 1,x - 1 });
        }
        if (!DP[t + 1][x]) {
            DP[t + 1][x] = DP[t][x];
            q.push_front({ t + 1,x });
        }
        if (x != 2000 && !DP[t + 1][x + 1]) {
            DP[t + 1][x + 1] = DP[t][x] + 1;
            q.push_back({ t + 1,x + 1 });
        }
    }

    cout << -1;



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