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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


ll sz[200002];
int state[200002];
int l[200001];
int r[200001];
int parent[200001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

vector<pii> ret;

void cal(int x) {
    if (findp(x) != x) return;
    int prv = findp(l[x] - 1); int nxt = findp(r[x] + 1);
    if (sz[x] * state[x] + sz[prv] * state[prv] < 0) {
        ret.push_back({ l[prv],r[x] });
        parent[prv] = x;
        sz[x] += sz[prv];
        state[x] = -1;
        r[l[prv]] = x;
        l[x] = l[prv];
        prv = findp(l[x] - 1); nxt = findp(r[x] + 1);
        cal(prv); cal(x); cal(nxt);
        return;
    }
    if (sz[x] * state[x] + sz[nxt] * state[nxt] < 0) {
        ret.push_back({ l[x],r[nxt] });
        parent[nxt] = x;
        sz[x] += sz[nxt];
        state[x] = -1;
        l[r[nxt]] = x;
        r[x] = r[nxt];
        prv = findp(l[x] - 1); nxt = findp(r[x] + 1);
        cal(prv); cal(x); cal(nxt);
        return;
    }
    if (sz[x] * state[x] + sz[prv] * state[prv] + sz[nxt] * state[nxt] < 0) {
        ret.push_back({ l[prv],r[nxt] });
        parent[prv] = parent[nxt] = x;
        sz[x] += sz[prv] + sz[nxt];
        state[x] = -1;
        r[l[prv]] = x;
        l[x] = l[prv];
        l[r[nxt]] = x;
        r[x] = r[nxt];
        prv = findp(l[x] - 1); nxt = findp(r[x] + 1);
        cal(prv); cal(x); cal(nxt);
        return;
    }
}

void solve(int tc) {

    int N;
    cin >> N;


    for (int i = 1; i <= N; i++) {
        cin >> state[i] >> sz[i];
        l[i] = i;
        r[i] = i;
        parent[i] = i;
    }

    state[0] = state[N + 1] = 1;
    sz[0] = sz[N + 1] = INF;


    for (int i = 1; i <= N; i++) {
        cal(i);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] == i && state[i] >= 0) {
            cout << -1;
            return;
        }
    }

    cout << ret.size() << endl;
    for (auto& [s, e] : ret) {
        cout << s << " " << e << endl;
    }




    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}