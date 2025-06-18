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


void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> E(N + 1);
    vector<vector<int>> rE(N + 1);
    vector<int> dist1(N + 1, 0), dist2(N + 1, 0);

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        rE[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    dist1[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (dist1[nx]) continue;
            dist1[nx] = dist1[x] + 1;
            q.push(nx);
        }
    }

    q.push(N);
    dist2[N] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : rE[x]) {
            if (dist2[nx]) continue;
            dist2[nx] = dist2[x] + 1;
            q.push(nx);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist1[i] && dist2[i] && dist1[i] + dist2[i] == 1 + dist1[N]) cout << i << " ";
    }
    cout << endl;



}
    


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}