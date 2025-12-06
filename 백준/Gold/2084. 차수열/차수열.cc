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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int arr[2001];
bool adj[2001][2001];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int k = 0; k < N; k++) {
        vector<vector<int>> bck(N);

        int mx = 0;
        for (int i = 1; i <= N; i++) {
            bck[arr[i]].push_back(i);
            mx = max(mx, arr[i]);
        }

        if (mx == 0) break;
        int x = bck[mx].back();
        bck[mx].pop_back();

        for (int b = mx; b >= 1; b--) {
            if (arr[x] >= bck[b].size()) {
                for (int nx : bck[b]) {
                    arr[x] -= 1;
                    arr[nx] -= 1;
                    adj[x][nx] = adj[nx][x] = true;
                }
            }
            else {
                for (int j = 0; j < arr[x]; j++) {
                    arr[bck[b][j]] -= 1;
                    adj[x][bck[b][j]] = adj[bck[b][j]][x] = true;
                }
                arr[x] = 0;
            }
        }

        if (arr[x] != 0) break;

    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] != 0) {
            cout << -1;
            return;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }






    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}