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

ll cnt[10001];
vector<pii> E[10001];
int dist[10001];

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {
    int N, M, T;
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        cin >> cnt[i];
        dist[i] = -1;
    }
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        E[a].push_back({ b,t });
        E[b].push_back({ a,t });
    }

    pq<pii, vector<pii>, cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        int x = q.top().first;
        int d = q.top().second;
        q.pop();
        if (dist[x] != -1) continue;
        dist[x] = d;
        for (pii& e: E[x]) {
            if (dist[e.first] != -1) continue;
            q.push({ e.first,e.second + d });
        }
    }

    vector<pii> v;
    for (int i = 1; i <= N; i++) {
        v.push_back({ dist[i],i });
    }
    sort(v.rbegin(), v.rend());

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        int x = v[i].second;
        if (x == 1) continue;

        ans = max(ans, cnt[x] * (dist[x] - T));

        int nx = inf;
        for (pii& e : E[x]) {
            if (dist[e.first] + e.second != dist[x]) continue;
            nx = min(nx, e.first);
        }
        cnt[nx] += cnt[x];

    }

    cout << ans;

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