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
const int inf = 1000000007;
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


bool isredundant(pair<__int128, __int128>& L1, pair<__int128, __int128>& L2, pair<__int128, __int128>& L3) {
    return (L2.first - L1.first) * (L1.second - L3.second) <= (L3.first - L1.first) * (L1.second - L2.second);
}

__int128 caculate(pair<__int128, __int128>& line, __int128 val) {
    return line.first * val + line.second;
}


void print128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        x = -x;
        cout << "-";
    }
    string s;
    while (x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

__int128 DP[1000001];

void solve(int tc) {

    int N;
    cin >> N;

    ll _a, _b, _c;
    cin >> _a >> _b >> _c;
    __int128 a, b, c;
    a = _a; b = _b; c = _c;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    deque<pair<__int128, __int128>> dq;

    __int128 psum = arr[0];
    DP[0] = a * psum * psum + b * psum + c;

    for (int i = 1; i < N; i++) {
        pair<__int128, __int128> newline = { a * psum * (-2), a * psum * psum - b * psum + DP[i - 1] };

        while (dq.size() >= 2 && isredundant(dq[dq.size() - 2], dq.back(), newline)) dq.pop_back();
        dq.push_back(newline);
        psum += arr[i];
        while (dq.size() >= 2 && caculate(dq.front(), psum) <= caculate(dq[1], psum)) dq.pop_front();
        DP[i] = max(caculate(dq.front(), psum), __int128(0)) + a * psum * psum + b * psum + c;
    }

    print128(DP[N - 1]);


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