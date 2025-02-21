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

int popcount(uint n) { // https://blog.naver.com/jinhan814/222540111549
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

vector<int> arr[10];
int DP[(1 << 10)][10][3];

void solve(int tc) {

    for (int T = 1; ; T++) {

        int N;
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i] = { x,y,z };
            sort(arr[i].begin(), arr[i].end());
        }

        for (int i = 0; i < (1 << N); i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 3; k++) {
                    DP[i][j][k] = 0;
                }
            }
        }


        int ans = 0;

        queue<vector<int>> q;
        q.push({ 0,-1,0 });
        while (!q.empty()) {
            int hist = q.front()[0];
            int x = q.front()[1];
            int k = q.front()[2];
            q.pop();

            for (int i = 0; i < N; i++) {
                if (hist & (1 << i)) continue;
                for (int nk = 0; nk < 3; nk++) {
                    if (hist == 0) {
                        q.push({ hist | (1 << i), i, nk });
                        DP[hist | (1 << i)][i][nk] = 1;
                        ans = max(ans, 1);
                        continue;
                    }
                    if (DP[hist | (1 << i)][i][nk]) continue;

                    int a, b;
                    if (k == 0) { a = arr[x][1], b = arr[x][2]; }
                    else if (k == 1) { a = arr[x][0]; b = arr[x][2]; }
                    else { a = arr[x][0], b = arr[x][1]; }

                    int na, nb;
                    if (nk == 0) { na = arr[i][1], nb = arr[i][2]; }
                    else if (nk == 1) { na = arr[i][0]; nb = arr[i][2]; }
                    else { na = arr[i][0], nb = arr[i][1]; }

                    if (na > a || nb > b) continue;
                    q.push({ hist | (1 << i),i,nk });
                    DP[hist | (1 << i)][i][nk] = DP[hist][x][k] + 1;
                    ans = max(ans, DP[hist | (1 << i)][i][nk]);
                }
            }

        }

        cout << "Case " << T << ": " << ans << endl;
    }




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