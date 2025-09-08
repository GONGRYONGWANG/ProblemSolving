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
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


vector<int> E[200001];
int A[200001], B[200001], C[200001];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int a, b, c;
    cin >> a >> b >> c;

    queue<int> q;
    q.push(a);
    A[a] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (A[nx]) continue;
            A[nx] = A[x] + 1;
            q.push(nx);
        }
    }

    q.push(b);
    B[b] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (B[nx]) continue;
            B[nx] = B[x] + 1;
            q.push(nx);
        }
    }


    q.push(c);
    C[c] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (C[nx]) continue;
            C[nx] = C[x] + 1;
            q.push(nx);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (E[i].size() != 1) continue;
        if (A[i] < B[i] && A[i] < C[i]) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";


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