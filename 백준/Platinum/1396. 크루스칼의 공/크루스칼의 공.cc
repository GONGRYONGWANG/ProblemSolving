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

int parent[100001];
int sz[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = { c,a,b };
    }

    sort(arr.begin(), arr.end());

    int Q;
    cin >> Q;
    vector<vector<int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        query[i] = { x,y,0,M }; // x,y,l,r
    }

    vector<pii> ret(Q);

    while (1) {

        bool f = false;
        vector<vector<int>> g(M+1);
        for (int i = 0; i < Q; i++) {
            if (query[i][2] != query[i][3]) f = true;
            g[(query[i][2] + query[i][3]) / 2].push_back(i);
        }

        for (int i = 1; i <= N; i++) {
            parent[i] = i; sz[i] = 1;
        }

        for (int i = 0; i < M; i++) {
            int u = arr[i][1]; int v = arr[i][2];
            u = findp(u); v = findp(v);
            if (u != v) sz[u] += sz[v];
            parent[v] = u;
            for (int idx : g[i]) {
                int x = query[idx][0]; int y = query[idx][1];
                x = findp(x); y = findp(y);
                if (x == y) {
                    query[idx][3] = i;
                    ret[idx] = { arr[i][0], sz[x] };
                }
                else query[idx][2] = i + 1;

            }
        }

        if (!f) break;
    }

    for (int i = 0; i < Q; i++) {
        if (query[i][2] == M) cout << -1;
        else cout << ret[i].first << " " << ret[i].second;
        cout << endl;
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