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

vector<int> E[100001];
bool visited[100001];
int cnt[100001];

int ind[100001];
int ret[100001];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<pii> edges;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        visited[x] = true;
        for (int nx : E[x]) {
            if (visited[nx]) continue;
            if (cnt[x] == 1) {
                edges.push_back({ x,nx });
                cnt[x] -= 1;
                cnt[nx] += 1;
            }
            else {
                edges.push_back({ nx,x });
                cnt[x] += 1;
                cnt[nx] -= 1;
            }
            q.push(nx);
        }
    }

    for (int i = 1; i <= N; i++) {
        E[i].clear();
    }

    for (auto [u, v] : edges) {
        E[u].push_back(v);
        ind[v] += 1;
    }

    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) q.push(i);
    }

    int idx = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ret[x] = ++idx;
        for (int nx : E[x]) {
            ind[nx] -= 1;
            if (ind[nx] == 0) q.push(nx);
        }
    }

    for (int i = 1; i <= N; i++) cout << ret[i] << " ";

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