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

ll adj[500][500];
int arr[100001][5];

void solve(int tc) {
    
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < 5 * X; i++) {
        for (int j = 0; j < 5 * X; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = inf;
        }
    }

    for (int i = 1; i <= N; i++) {

        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            arr[i][j] = j * X + arr[i][j] - 1;
        }

        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                if (a == b) continue;
                adj[arr[i][a]][arr[i][b]] = 1;
            }
        }
    }

    for (int k = 0; k < 5 * X; k++) {
        for (int i = 0; i < 5 * X; i++) {
            for (int j = 0; j < 5 * X; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }


    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        ll ret = inf;
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                ret = min(ret, adj[arr[u][a]][arr[v][b]]);
            }
        }
        if (ret == inf) cout << -1;
        else cout << ret + 1;
        cout << endl;
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