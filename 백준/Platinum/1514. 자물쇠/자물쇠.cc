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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

int N;
string A, B;
int DP[101][10][10];

void solve() {

    cin >> N >> A >> B;
    for (int x = N-1; x >=0 ; x--) {
        for (int p = 0; p < 10; p++) {
            for (int pp = 0; pp < 10; pp++) {
                DP[x][p][pp] = 1000;
                int cur = A[x] - '0';
                int tar = B[x] - '0';
                cur = (cur + p + pp) % 10;
                for (int i = -9; i <= 9; i++) { // len 3
                    for (int j = -9; j <= 9; j++) { // len 2
                        int a = abs(i); int b = abs(j);
                        int ret = (a + 2) / 3 + (b + 2) / 3;
                        ret += (min(abs((cur + i + j + 20) % 10 - tar), 10 - abs((cur + i + j + 20) % 10 - tar)) + 2) / 3;
                        ret += DP[x + 1][(i + 10) % 10][(p + j + 10) % 10];
                        DP[x][p][pp] = min(DP[x][p][pp], ret);
                    }
                }
            }
        }
    }

    cout << DP[0][0][0];

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

