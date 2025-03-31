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


pii arr[100001][2];
vector<int> E[100001][2];

void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        E[u][0].push_back(v);
        E[v][1].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        arr[i][0] = arr[i][1] = { 0,0 };
    }

    for (int i = 1; i <= Q; i++) {
        int x, d, c;
        cin >> x >> d >> c;
        d -= 1;
        arr[x][d] = { i,c };
    }

    for (int i = 1; i <= N; i++) {
        for (int nx : E[i][0]) {
            arr[nx][0] = max(arr[nx][0], arr[i][0]);
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int nx : E[i][1]) {
            arr[nx][1] = max(arr[nx][1], arr[i][1]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << max(arr[i][0], arr[i][1]).second << " ";
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