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

int board[301][301];
int rsum[301];
int csum[301];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            rsum[i] += board[i][j];
            csum[j] += board[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        pii mx = { -inf,-inf };
        for (int j = 1; j <= N; j++) {
            int ret = csum[j] - 2 * board[i][j];
            if (ret >= mx.first) mx = { ret,mx.first };
            else if (ret > mx.second) mx.second = ret;
        }
        ans = max(ans, rsum[i] + mx.first + mx.second);
    }

    for (int j = 1; j <= N; j++) {
        pii mx = { -inf,-inf };
        for (int i = 1; i <= N; i++) {
            int ret = rsum[i] - 2 * board[i][j];
            if (ret >= mx.first) mx = { ret,mx.first };
            else if (ret > mx.second) mx.second = ret;
        }
        ans = max(ans, csum[j] + mx.first + mx.second);
    }


    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            pii idxa = { 0,0 };
            pii idxb = { 0,0 };
            pii mxa = { -inf,-inf };
            pii mxb = { -inf,-inf };
            for (int j = 1; j <= N; j++) {
                int reta = csum[j] - 2 * board[a][j] - board[b][j];
                if (reta >= mxa.first) {
                    mxa = { reta, mxa.first };
                    idxa = { j,idxa.first };
                }
                else if (reta > mxa.second) {
                    mxa.second = reta;
                    idxa.second = j;
                }

                int retb = csum[j] - 2 * board[b][j] - board[a][j];
                if (retb >= mxb.first) {
                    mxb = { retb, mxb.first };
                    idxb = { j,idxb.first };
                }
                else if (retb > mxb.second) {
                    mxb.second = retb;
                    idxb.second = j;
                }
            }

            if (idxa.first != idxb.first) {
                ans = max(ans, rsum[a] + rsum[b] + mxa.first + mxb.first);
            }
            else {
                ans = max(ans, rsum[a] + rsum[b] + max(mxa.first + mxb.second, mxa.second + mxb.first));
            }
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