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

vector<pii> E[100001];
int idx[100001];

int parent[100001];
int sz[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}


ll A[100002];
ll B[100001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i; sz[i] = 1;
    }

    vector<tuple<ll, ll, ll>> query(M);
    for (int i = 0; i < M; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        query[i] = { t,x,y };
    }

    for (auto [t, x, y] : query) {
        if (t == 2) continue;
        x = findp(x); y = findp(y);
        if (x > y) swap(x, y);
        E[x].push_back({ y,sz[x] });
        sz[x] += sz[y];
        parent[y] = x;
    }

    idx[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto [nx, d] : E[x]) {
            idx[nx] = idx[x] + d;
            q.push(nx);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i; sz[i] = 1;
    }

    for (auto [t, x, y] : query) {
        if (t == 1) {
            x = findp(x); y = findp(y);
            if (x > y) swap(x, y);
            sz[x] += sz[y];
            parent[y] = x;
        }
        else {
            B[x] -= y;
            x = findp(x);
            A[idx[x]] += y / sz[x];
            A[idx[x] + sz[x]] -= y / sz[x];
        }
    }

    for (int i = 1; i <= N; i++) A[i] += A[i - 1];
    for (int i = 1; i <= N; i++) B[i] += A[idx[i]];


    vector<tuple<ll,ll,ll>> ret;
    for (int i = 2; i <= N; i++) {
        if (B[i]== 0) continue;
        ret.push_back({ i,1,B[i] });
    }

    cout << ret.size() << endl;

    for (auto [u, v, w] : ret) {
        if (w < 0) swap(u, v);
        cout << u << " " << v << " " << abs(w) << endl;
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