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

int E[1000000];
int ind[1000000];
ll sz[1000000];
ll ext[1000000];
bool visited[1000000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        E[i] = i * 2 % M;
        ind[E[i]] += 1;
    }

    while (N--) {
        int x; cin >> x;
        sz[x] += 1;
    }

    queue<int> q;
    for (int i = 0; i < M; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        visited[x] = true;
        sz[E[x]] += sz[x];
        ext[E[x]] += ext[x] + sz[x];
        ind[E[x]] -= 1;
        if (ind[E[x]] == 0) q.push(E[x]);
    }

    ll mx = 0; ll op = INF;
    for (int i = 0; i < M; i++) {
        if (visited[i]) continue;
        ll ret = ext[i];
        ll cnt = sz[i];
        ll len = 1;
        visited[i] = true;

        int x = E[i];
        while (x != i) {
            cnt += sz[x];
            ret += ext[x];
            len += 1;
            visited[x] = true;
            x = E[x];
        }

        if (cnt < mx) continue;
        if (cnt > mx) op = INF;
        mx = max(cnt, mx);

        ll d = 1;
        x = E[i];
        while (x != i) {
            ret += sz[x] * (len - d);
            d += 1;
            x = E[x];
        }

        op = min(op, ret);
        x = i;
        while (E[x] != i) {
            x = E[x];
            ret += cnt - sz[x] * len;
            op = min(op, ret);
        }
    }

    for (int i = 0; i < M; i++) {
        if (sz[i] == mx) op = min(op, ext[i]);
    }

    cout << mx << " " << op;

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