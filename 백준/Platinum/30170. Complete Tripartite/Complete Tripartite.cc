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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<int> E[100001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    if (M == 0) {
        cout << -1;
        return;
    }
    int a, b;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
        a = u, b = v;
    }

    vector<bool> cona(N + 1, false), conb(N + 1, false);
    for (int x : E[a]) cona[x] = true;
    for (int x : E[b]) conb[x] = true;

    vector<int> col(N + 1);
    col[a] = 0; col[b] = 1;

    vector<ll> cnt(3, 0);

    cnt[0] += 1; cnt[1] += 1;

    for (int i = 1; i <= N; i++) {
        if (i == a || i == b) continue;
        if (cona[i] && conb[i]) col[i] = 2;
        else if (cona[i]) col[i] = 1;
        else if(conb[i]) col[i] = 0;
        else {
            cout << -1;
            return;
        }
        cnt[col[i]] += 1;
    }

    if (cnt[2] == 0) {
        cout << -1;
        return;
    }

    ll m = cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
    if (m != M) {
        cout << -1;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (E[i].size() != N - cnt[col[i]]) {
            cout << -1;
            return;
        }
        for (int x : E[i]) {
            if (col[x] == col[i]) {
                cout << -1;
                return;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << col[i] + 1 << " ";
    }




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}