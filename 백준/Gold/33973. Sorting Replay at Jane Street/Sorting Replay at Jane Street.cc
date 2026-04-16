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

int board[2001][2001];
int N, Q;

ll mod = 998244353;

vector<pii> query;

ll F[2001];

ll dnc(vector<int> v, int q) {
    if (q == Q) return 1;
    int t = query[q].first;
    int j = query[q].second;

    unordered_map<int, vector<int>> m;
    for (int x : v) m[board[x][j]].push_back(x);


    ll ret = 1;

    for (auto it = m.begin(); it != m.end(); it++) {
        if (t == 1) ret = ret * F[(it->second).size()] % mod;
        else ret = ret * dnc(it->second, q + 1) % mod;
    }
    return ret;
}


void solve(int tc) {
    cin >> N >> Q;

    F[0] = 1;
    for (int i = 1; i <= N; i++) {
        F[i] = F[i - 1] * i % mod;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < Q;  i++) {
        int t, j;
        cin >> t >> j;
        query.push_back({ t,j });
    }

    reverse(query.begin(), query.end());

    vector<int> v(N);
    for (int i = 1; i <= N; i++) v[i-1] = i;
    cout << dnc(v, 0);






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