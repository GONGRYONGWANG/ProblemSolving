// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    
    vector<pii> arr(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first;
        if (arr[i].first == 0) arr[i].first = inf;
    }
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].second;
        if (arr[i].second == 0) arr[i].second = inf;
    }

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }


    pq<pii, vector<pii>, cmp> q;
    q.push({ 1,0 });
    vector<int> dist1(N + 1, -1);
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (dist1[x] != -1) continue;
        dist1[x] = d;
        for (pii& e : E[x]) {
            if (dist1[e.first] != -1) continue;
            q.push({ e.first, e.second + d });
        }
    }
    
    int a = 1, b = 1;
    for (int i = 1; i <= N; i++) {
        if (dist1[i] == -1) continue;
        if (arr[i].first < arr[a].first) a = i;
        if (arr[i].second < arr[b].second) b = i;
    }


    vector<int> dista(N + 1, -1);
    q.push({ a,0 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (dista[x] != -1) continue;
        dista[x] = d;
        for (pii& e : E[x]) {
            if (dista[e.first] != -1) continue;
            q.push({ e.first, e.second + d });
        }
    }

    cout << dist1[a] + dist1[b] + dista[b];




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