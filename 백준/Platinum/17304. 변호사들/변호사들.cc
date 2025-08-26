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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

unordered_set<pii,PiiHasher> edges;
vector<pii> biedge;
vector<int> E[200001];

bool visited[200001];

int parent[200001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}
bool cycle[200001];


void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        if (edges.count({ v,u })) {
            edges.erase({ v,u });
            biedge.push_back({ u,v });
        }   
        else edges.insert({ u,v });
    }

    for (auto& [u, v] : edges) {
        visited[v] = true;
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        if (!visited[i]) continue;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nx : E[x]) {
                if (visited[nx]) continue;
                visited[nx] = true;
                q.push(nx);
            }
        }
    }

    for (auto& [u, v] : biedge) {
        if (visited[u] || visited[v]) continue;
        if (findp(u) == findp(v)) {
            cycle[findp(u)] = true;
            continue;
        }
        cycle[findp(u)] |= cycle[findp(v)];
        parent[findp(v)] = findp(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i] && !cycle[findp(i)]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";




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