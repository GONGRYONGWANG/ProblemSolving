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

int parent[150001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void mer(int a, int b) {
    a = findp(a); b = findp(b);
    parent[b] = a;
}

void solve(int tc) {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        parent[i] = i; parent[i + N] = i + N;
        parent[i + 2 * N] = i + 2 * N;
    }

    int ans = 0;

    while (K--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x <= 0 || x > N || y <= 0 || y > N) {
            ans += 1;
            continue;
        }

        if (t == 2) {
            if (findp(x + N) == findp(y)) continue;
            if (findp(x) == findp(y) || findp(x) == findp(y + N)) {
                ans += 1;
                continue;
            }
            mer(x + N, y); mer(x + 2 * N, y + N); mer(x, y + 2 * N);
        }
        else {
            if (findp(x) == findp(y)) continue;
            if (findp(x) == findp(y + N) || findp(x + N) == findp(y)) {
                ans += 1;
                continue;
            }
            mer(x, y); mer(x + N, y + N); mer(x + 2 * N, y + 2 * N);
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