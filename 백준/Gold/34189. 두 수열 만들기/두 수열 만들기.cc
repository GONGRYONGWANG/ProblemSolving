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


int popcount(uint n) { // https://blog.naver.com/jinhan814/222540111549
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

int parent[4001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

int sz[4001];

int DP[4001][2001];

void solve(int tc) {

    int N;
    cin >> N;

    vector<int> arr(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++) {
        cin >> arr[i];
        parent[i] = i;
    }

    for (int i = 1; i <= 2 * N; i++) {
        for (int j = i + 1; j <= 2 * N; j++) {
            if (popcount(arr[i]^ arr[j]) == 1) {
                parent[findp(j)] = findp(i);
            }
        }
    }

    vector<vector<int>> child(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++) {
        sz[findp(i)] += 1;
        child[findp(i)].push_back(i);
    }

    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= N; j++) {
            DP[i][j] = -1;
        }
    }

    DP[0][0] = 0;
    for (int i = 1; i <= 2 * N; i++) {
        for (int j = N; j >= 0; j--) {
            DP[i][j] = DP[i - 1][j];
        }
        if (findp(i) != i) continue;
        for (int j = N - sz[i]; j >= 0; j--) {
            if (DP[i - 1][j] == -1) continue;
            if (DP[i][j + sz[i]] != -1) continue;
            DP[i][j + sz[i]] = i;
        }
    }

    if (DP[2 * N][N] == -1) {
        cout << -1;
        return;
    }

    vector<bool> ret(2 * N + 1, false);

    int total = N;
    int x = 2 * N;

    while (total != 0) {
        x = DP[x][total];
        total -= sz[x];
        for (int d : child[x]) {
            ret[d] = true;
        }
        x -= 1;
    }

    for (int i = 1; i <= 2 * N; i++) {
        if (ret[i]) cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 2 * N; i++) {
        if (!ret[i]) cout << arr[i] << " ";
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