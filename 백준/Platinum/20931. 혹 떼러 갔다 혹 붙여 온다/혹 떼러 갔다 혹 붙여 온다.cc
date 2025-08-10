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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

pll parent[150001][18];

void solve(int tc) {
    
    int Q;
    cin >> Q;

    ll last_ans = 0;
    ll M = 1;

    for (int j = 0; j < 18; j++) parent[0][j] = { 0,INF };

    while (Q--) {
        string s;
        cin >> s;
        if (s.front() == 'q') {
            ll x, L;
            cin >> x >> L;
            for (int j = 17; j >= 0; j--) {
                if (L >= parent[x][j].second) {
                    L -= parent[x][j].second;
                    x = parent[x][j].first;
                }
            }
            cout << x << endl;
            last_ans = x;
        }
        else {
            ll k, L;
            cin >> k >> L;

            ll x = (k + last_ans) % M;
            parent[M][0] = { x,L };
            for (int j = 1; j < 18; j++) {
                parent[M][j].first = parent[parent[M][j - 1].first][j - 1].first;
                parent[M][j].second = min(INF, parent[parent[M][j - 1].first][j - 1].second + parent[M][j - 1].second);
            }

            M += 1;
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