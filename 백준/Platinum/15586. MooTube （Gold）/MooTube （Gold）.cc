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

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> E(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = { w,u,v };
    }
    sort(E.rbegin(), E.rend());
    
    vector<vector<int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        query[i] = { k,v ,i };
    }
    sort(query.rbegin(), query.rend());

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    vector<int> ans(Q);

    int idx = 0;
    for (int i = 0; i < Q; i++) {
        int k = query[i][0]; int v = query[i][1];
        while (idx != N - 1 && E[idx][0] >= k) {
            int a = E[idx][1]; int b = E[idx][2];
            a = findp(a); b = findp(b);
            if (a == b) continue;
            sz[a] += sz[b];
            parent[b] = a;
            idx += 1;
        }

        ans[query[i][2]] = sz[findp(v)];

    }

    for (int ret : ans) {
        cout << ret - 1 << endl;
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