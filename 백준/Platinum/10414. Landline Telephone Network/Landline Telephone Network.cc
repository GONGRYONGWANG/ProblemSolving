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
const int inf = 1000000007;
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

vector<pii> E[1001];
bool visited[1001];
struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

bool insecure[1001];

void solve(int tc) {

    int N, M, P;
    cin >> N >> M >> P;

    for (int i = 0; i < P; i++) {
        int x; cin >> x;
        insecure[x] = true;
    }

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    ll ans = 0;
    pq<pii, vector<pii>, cmp> q;

    if (P == N) {

        q.push({ 1,0 });
        while (!q.empty()) {
            auto [x, d] = q.top();
            q.pop();
            if (visited[x]) continue;
            visited[x] = true;
            ans += d;
            for (pii& e : E[x]) {
                if (visited[e.first]) continue;
                q.push(e);
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                cout << "impossible";
                return;
            }
        }

        cout << ans;
        return;

    }

    for (int i = 1; i <= N; i++) {
        if (!insecure[i]) {
            q.push({ i,0 });
            break;
        }
    }

    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        ans += d;
        for (pii& e : E[x]) {
            if (visited[e.first] || insecure[e.first]) continue;
            q.push(e);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!insecure[i]) continue;
        int mn = inf;
        for (pii& e : E[i]) {
            if (insecure[e.first]) continue;
            mn = min(e.second, mn);
        }
        if (mn == inf) {
            cout << "impossible";
            return;
        }
        ans += mn;
        visited[i] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "impossible";
            return;
        }
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