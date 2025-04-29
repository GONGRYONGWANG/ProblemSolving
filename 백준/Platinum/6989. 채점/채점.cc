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


bitset<1132501> dp[151];
bitset<1132501> nx[151];
bitset<1132501> ret;

void solve(int tc) {

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    reverse(arr.begin(), arr.end());


    dp[0][0] = true;

    for (int x : arr) {
        for (int i = 0; i < N; i++) {
            nx[i + 1] |= dp[i] << (x * (i + 1));
            nx[0] |= dp[i];
        }
        for (int i = 0; i <= N; i++) {
            dp[i] = nx[i];
            nx[i].reset();
        }
    }

    for (int i = 0; i <= N; i++) {
        ret |= dp[i];
    }

    int K;
    cin >> K;

    if (K > 1132500) {
        cout << K;
        return;
    }

    for (int i = K; i <= 1132500; i++) {
        if (!ret[i]) {
            cout << i;
            return;
        }
    }

    cout << 1132501;




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