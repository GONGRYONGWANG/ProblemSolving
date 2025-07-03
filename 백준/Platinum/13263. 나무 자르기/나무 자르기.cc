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


bool isredundant(pair<__int128, __int128>& a, pair<__int128, __int128>& b, pair<__int128, __int128>& c) { // 가운데 라인이 무의미 한지 확인.
    return (b.second - a.second) * (b.first - c.first) >= (c.second - b.second) * (a.first - b.first);
}

__int128 caculate(pair<__int128, __int128>& line, __int128 val) {
    return line.first * val + line.second;
}

__int128 DP[100000];

void print128(__int128 x){
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve(int tc) {

    int N;
    cin >> N;

    
    vector<pll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first;
    for (int i = 0; i < N; i++) cin >> arr[i].second;

    __int128 ret = -arr[N - 1].second;
    for (int i = 0; i < N; i++) {
        ret += arr[i].first * arr[N - 1].second;
        arr[i].second -= arr[N - 1].second;
    }

    DP[0] = 0;

    deque<pair<__int128,__int128>> dq;
    for (int i = 1; i < N; i++) {
        pair<__int128, __int128> newline = { arr[i - 1].second, DP[i - 1] };
        while (dq.size() >= 2 && isredundant(dq[dq.size() - 2], dq.back(), newline)) dq.pop_back();
        dq.push_back(newline);

        while (dq.size() >= 2 && caculate(dq.front(), arr[i].first) >= caculate(dq[1], arr[i].first)) dq.pop_front();
        DP[i] = caculate(dq.front(), arr[i].first);
    }

    ret += DP[N - 1];

    print128(ret);
    




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