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
//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<pii> edges[5];
int parent[50001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;
    while (M--) {
        int u, v; char z;
        cin >> u >> v >> z;
        edges[z - 'A'].push_back({ u,v });
    }

    vector<ll> ans(Q);
    vector<tuple<vector<int>, vector<ll>, int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        vector<pii> v = { {a,0},{b,1},{c,2},{d,3},{e,4} };
        sort(v.begin(), v.end());
        vector<int> order(5);
        for (int j = 0; j < 5; j++) order[j] = v[j].second;
        query[i] = { order,{a,b,c,d,e},i };
    }

    sort(query.begin(), query.end());

    vector<int> cnt = { 0,0,0,0,0 };
    vector<int> prvorder = { 0,0,0,0,0 };
    for (auto [order, val, idx] : query) {
        ll ret = 0;
        if (order != prvorder) {
            cnt = { 0,0,0,0,0 };
            for (int i = 1; i <= N; i++) parent[i] = i;
            for (int x : order) {
                for (auto [u, v] : edges[x]) {
                    if (findp(u) == findp(v)) continue;
                    cnt[x] += 1;
                    parent[findp(u)] = findp(v);
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            ret += val[i] * cnt[i];
        }
        ans[idx] = ret;
        prvorder = order;
    }

    for (ll ret : ans) {
        cout << ret << endl;
    }

    //cout << "Case #" << tc << ": " << debug << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}