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


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

bool adj[5001][5001];

bool cmp(pii& a, pii& b) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return x1 * y2 < x2 * y1;
}

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            for (int k = i; k <= j; k += i) {
                adj[j][k] = true;
            }
        }
    }

    vector<pii> arr;
    arr.push_back({ 0,1 });
    arr.push_back({ 1,1 });

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (!adj[i][j]) arr.push_back({ j,i });
        }
    }

    nth_element(arr.begin(), arr.begin() + K - 1, arr.end(), cmp);

    cout << arr[K - 1].first << " " << arr[K - 1].second;



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