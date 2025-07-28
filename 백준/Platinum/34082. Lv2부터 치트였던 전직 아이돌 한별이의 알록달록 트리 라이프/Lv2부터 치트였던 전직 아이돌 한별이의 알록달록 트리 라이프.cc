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

vector<int> E[300001];

int parent[300001];
int ind[300001];

ll A[300001], B[300001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (nx == parent[x]) continue;
            parent[nx] = x;
            ind[x] += 1;
            q.push(nx);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        A[x] = B[x] = 1;
        for (int nx : E[x]) {
            if (nx == parent[x]) continue;
            A[x] *= A[nx]; A[x] %= M;
            A[x] += B[x] * B[nx]; A[x] %= M;
            B[x] *= A[nx]; B[x] %= M;
        }

        if (parent[x] != 0) {
            ind[parent[x]] -= 1;
            if (ind[parent[x]] == 0) q.push(parent[x]);
        }
    }

    ll ret = 1;
    for (int i = 1; i <= N; i++) {
        ret *= 2; ret %= M;
    }

    cout << (ret - 2 * A[1] + 2 * M) % M;


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