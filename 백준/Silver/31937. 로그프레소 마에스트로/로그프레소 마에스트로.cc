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
#define INF ll(4e18)
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




bitset<1001> bs[1001];

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    vector<bool> cont(N + 1, false);
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        cont[x] = true;
    }


    for (int i = 1; i <= N; i++){
        bs[i][i] = true;
    }


    vector<vector<int>> edge(M);
    for (int i = 0; i < M; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        edge[i] = { t,a,b };
    }
    sort(edge.begin(), edge.end());

    for (vector<int>& e : edge) {
        int u = e[1]; int v = e[2];
        bs[v] |= bs[u];
    }

    for (int i = 1; i <= N; i++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            if (cont[j] != bs[j][i]) flag = false;
        }
        if (flag) {
            cout << i;
            return;
        }
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