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



ll total[200001];
ll thres[200001];
vector<int> E[200001];
int p[200001];
bool inpath[200001];
set<pll> st[200001];

void mer(int a, int b) {
    if (st[a].size() < st[b].size()) swap(st[a], st[b]);
    for (auto& tmp : st[b]) {
        st[a].insert(tmp);
    }
}

void dfs(int x) {
    for (int nx : E[x]) {
        if (nx == p[x]) continue;
        dfs(nx);
    }

    while (total[x] <= 0 && !st[x].empty()) {
        auto [v, nx] = *st[x].begin();
        st[x].erase(st[x].begin());
        thres[x] = max(thres[x], thres[nx] - total[x]);
        total[x] += total[nx];
        mer(x, nx);
    }
    
    if (total[x] > 0) st[p[x]].insert({ thres[x],x });

}

void solve(int tc) {

    int N;
    cin >> N;

    int t; cin >> t;

    st[0].clear();
    thres[0] = total[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> total[i];
        thres[i] = max(0ll, -total[i]);
        p[i] = 0;
        E[i].clear();
        inpath[i] = false;
        st[i].clear();
    }

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
            if (nx == p[x]) continue;
            p[nx] = x;
            q.push(nx);
        }
    }

    vector<int> path;
    while (t != 0) {
        path.push_back(t);
        inpath[t] = true;
        t = p[t];
    }
    reverse(path.begin(), path.end());

    for (int cur : path) {
        if (thres[cur] > total[0]) {
            cout << "trapped" << endl;
            return;
        }

        total[0] += total[cur];
        for (int nx : E[cur]) {
            if (inpath[nx]) continue;
            dfs(nx);
        }
        mer(0, cur);

        while (!st[0].empty() && st[0].begin()->first <= total[0]) {
            int nx = st[0].begin()->second;
            st[0].erase(st[0].begin());
            total[0] += total[nx];
            mer(0, nx);
        }

    }

    cout << "escaped" << endl;


    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}