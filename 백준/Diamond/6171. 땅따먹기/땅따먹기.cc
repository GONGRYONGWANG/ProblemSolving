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

ll DP[50000];

bool isredundant(pll& a, pll& b, pll& c) {
    return (b.second - a.second) * (b.first - c.first) >= (c.second - b.second) * (a.first - b.first);
}

ll caculate(pll& line, ll val) {
    return line.first * val + line.second;
}

void solve(int tc) {

    int N;
    cin >> N;
    vector<pll> init(N);
    for (int i = 0; i < N; i++) cin >> init[i].first >> init[i].second;
    sort(init.begin(), init.end());

    vector<pll> arr;
    for (auto [w, h] : init) {
        while (!arr.empty() && arr.back().second <= h) arr.pop_back();
        arr.push_back({ w,h });
    }

    reverse(arr.begin(), arr.end());

    N = arr.size();

    deque<pll> dq;

    for (int i = 0; i < N; i++) {
        auto [w, h] = arr[i];
        pll newline = { w,0 };
        if (i != 0) newline.second = DP[i - 1];

        while (dq.size() >= 2 && isredundant(dq[dq.size() - 2], dq.back(), newline)) dq.pop_back();
        dq.push_back(newline);

        while (dq.size() >= 2 && caculate(dq.front(), h) >= caculate(dq[1], h)) dq.pop_front();
        DP[i] = caculate(dq.front(), h);
    }

    cout << DP[N - 1]; 


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