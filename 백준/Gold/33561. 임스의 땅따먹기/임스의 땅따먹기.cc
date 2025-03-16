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

int board[501][501];
pii rsum[501][501];
pii csum[501][501];

void solve(int tc) {

    int N;
    cin >> N;
    

    for (int i = 1; i <= N; i++) {
        rsum[i][0] = csum[0][i] = { 0,0 };
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            rsum[i][j] = rsum[i][j - 1]; csum[i][j] = csum[i - 1][j];
            if (board[i][j]) {
                rsum[i][j].first += board[i][j];
                csum[i][j].first += board[i][j];
            }
            else{
                rsum[i][j].second += 1;
                csum[i][j].second += 1;
            }
        }
    }

    int K;
    cin >> K;
    vector<int> arr(K);
    for (int& x : arr) cin >> x;
    sort(arr.rbegin(), arr.rend());
    for (int i = 1; i < K; i++) arr[i] += arr[i - 1];

    for (int i = 1; i <= N; i++) {
        int l = 1;
        int r = 2;
        pii ret = rsum[i][1];
        while (1) {
            while (ret.second > K) {
                ret.first -= rsum[i + r - l - 1][r - 1].first - rsum[i + r - l - 1][l - 1].first;
                ret.second -= rsum[i + r - l - 1][r - 1].second - rsum[i + r - l - 1][l - 1].second;
                ret.first -= csum[i + r - l - 1][l].first - csum[i - 1][l].first;
                ret.second -= csum[i + r - l - 1][l].second - csum[i - 1][l].second;
                ret.first += board[i + r - l - 1][l]; ret.second += (board[i + r - l - 1][l] == 0);
                l += 1;
            }

            if (ret.second == 0) ans = max(ans, ret.first);
            else ans = max(ans, ret.first + arr[ret.second - 1]);
            
            if (i + r - l > N || r > N) break;
            ret.first += rsum[i + r - l][r].first - rsum[i + r - l][l - 1].first;
            ret.second += rsum[i + r - l][r].second - rsum[i + r - l][l - 1].second;
            ret.first += csum[i + r - l][r].first - csum[i - 1][r].first;
            ret.second += csum[i + r - l][r].second - csum[i - 1][r].second;
            ret.first -= board[i + r - l][r]; ret.second -= (board[i + r - l][r]== 0);
            r += 1;
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