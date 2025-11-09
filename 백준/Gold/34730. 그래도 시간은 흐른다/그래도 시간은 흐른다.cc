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

bool visited[100001][31];

vector<tuple<ll,ll,ll>> E[100001];

struct cmp {
    bool operator()(tuple<ll, ll, ll>& a, tuple<ll, ll, ll>& b) {
        auto& [ax, ay, at] = a; auto& [bx, by, bt] = b;
        return at > bt;
    }
};

void solve(int tc) {

    int N, M, K, S, T;
    cin >> N >> M >> K >> S >> T;

    while (M--) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        E[u].push_back({ v,a,b });
    }

    pq<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, cmp> q;
    for (int i = 1; i <= K; i++) q.push({ S,i,0 });
    while (!q.empty()) {
        auto [x, k, t] = q.top();
        q.pop();
        if (visited[x][k]) continue;
        visited[x][k] = true;
        if (x == T) {
            cout << t;
            return;
        }
        for (auto& [nx, d, nk] : E[x]) {
            if (visited[nx][nk]) continue;
            if (t % nk) continue;
            ll nt = t + d;
            for (int i = 1; i <= K; i++) {
                if (nt % i) continue;
                if (visited[nx][i]) continue;
                q.push({ nx,i,nt });
            }
        }
    }

    cout << -1;



    // cout << "Case #" << tc << ": " << ret<< endl;
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