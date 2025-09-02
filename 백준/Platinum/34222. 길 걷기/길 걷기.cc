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



void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N + 1, vector<int>(M)), B(N + 1, vector<int>(M)), 
        a(N + 1, vector<int>(M)), b(N + 1, vector<int>(M));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            cin >> b[i][j];
        }
    }

    ll ans = 0;

    for (int j = 1; j < M; j++) {

        vector<int> ind(N + 1, 0);
        vector<vector<int>> rE(N + 1);
        for (int i = 1; i <= N; i++) {
            int u = A[i][j]; int v = B[i][j];
            ind[u] += 1; ind[v] += 1;
            rE[u].push_back(i);
            rE[v].push_back(i);
        }

        vector<bool> conquered(N + 1, false);
        vector<bool> visited(N + 1, false);

        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;
            if (ind[i] == 0) {
                cout << -1;
                return;
            }
            if (ind[i] > 1) continue;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                for (int nx : rE[x]) {
                    if (conquered[nx]) continue;
                    conquered[nx] = true;

                    if (x == A[nx][j]) {
                        ans += a[nx][j];
                        ind[B[nx][j]] -= 1;
                        if (ind[B[nx][j]] == 0) {
                            cout << -1;
                            return;
                        }
                        else if (ind[B[nx][j]] == 1) {
                            x = B[nx][j];
                        }
                    }
                    else {
                        ans += b[nx][j];
                        ind[A[nx][j]] -= 1;
                        if (ind[A[nx][j]] == 0) {
                            cout << -1;
                            return;
                        }
                        else if (ind[A[nx][j]] == 1) {
                            x = A[nx][j];
                        }
                    }
                    break;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (conquered[i]) continue;
            ll sum1 = 0; ll sum2 = 0;

            int x = i;
            while (!conquered[x]) {
                conquered[x] = true;
                if (!visited[A[x][j]]) {
                    visited[A[x][j]] = true;
                    sum1 += a[x][j];
                    sum2 += b[x][j];
                    for (int nx : rE[A[x][j]]) {
                        if (!conquered[nx]) x = nx;
                    }
                }
                else {
                    visited[B[x][j]] = true;
                    sum1 += b[x][j];
                    sum2 += a[x][j];
                    for (int nx : rE[B[x][j]]) {
                        if (!conquered[nx]) x = nx;
                    }
                }
            }

            ans += min(sum1, sum2);
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