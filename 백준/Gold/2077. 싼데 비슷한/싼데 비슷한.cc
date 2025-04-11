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
#define INF ll(4e18+7)
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
    ll total = 0;
    vector<ll> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    vector<ll> DP(N + 2);
    DP[N + 1] = 0;
    for (int i = N - 1; i >= 1; i--) {
        DP[i] = DP[i + 1];
        if (i + 2 <= N + 1) DP[i] = max(DP[i], DP[i + 2] + arr[i + 1]);
        if (i + 3 <= N + 1) DP[i] = max(DP[i], DP[i + 3] + arr[i + 2] + arr[i + 1]);
        if (i + 4 <= N + 1) DP[i] = max(DP[i], DP[i + 4] + arr[i + 3] + arr[i + 2] + arr[i + 1]);
    }

    if (DP[1] * 4 < 3 * total) {
        cout << "NO" << endl;
        return;
    }
    else cout << "YES" << endl;

    int x = 1;
    while (x <= N) {
        if (DP[x] == DP[x + 1]) {
            cout << "0";
            x = x + 1;
            continue;
        }
        if (DP[x] == DP[x + 2] + arr[x + 1]) {
            cout << "01";
            x = x + 2;
            continue;
        }
        if (DP[x] == DP[x + 3] + arr[x + 2] + arr[x + 1]) {
            cout << "022";
            x = x + 3;
            continue;
        }
        else {
            cout << "0333";
            x = x + 4;
        }
    }
    cout << endl;


}
    



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}