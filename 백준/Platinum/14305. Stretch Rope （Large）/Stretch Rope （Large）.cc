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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


ll DP[10001];

void solve(int tc) {

    ll N, M, L;
    cin >> N >> M >> L;
    
    for (int i = 0; i <= L; i++) {
        DP[i] = INF;
    }

    DP[0] = 0;

    while (N--) {
        ll a, b, p;
        cin >> a >> b >> p;

        if (a > L) continue;
        b = min(b, L);

        deque<int> dq;
        for (int j = L - a; j >= L - b; j--) {
            while (!dq.empty() && DP[dq.front()] >= DP[j]) dq.pop_front();
            dq.push_front(j);
        }

        DP[L] = min(DP[L], DP[dq.back()] + p);

        for (int i = L - 1; i >= a; i--) {
            if (i >= b) {
                while (!dq.empty() && DP[dq.front()] >= DP[i - b]) dq.pop_front();
                dq.push_front(i - b);
            }
            if (dq.back() == i - a + 1) dq.pop_back();
            DP[i] = min(DP[i], DP[dq.back()] + p);
        }
    }
    cout << "Case #" << tc << ": ";
    if (DP[L] > M) cout << "IMPOSSIBLE";
    else cout<<DP[L];
    cout << endl;



    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}