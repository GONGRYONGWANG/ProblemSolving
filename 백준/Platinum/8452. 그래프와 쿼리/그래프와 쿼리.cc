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


int dist[1001];
vector<int> E[1001];

void update(int r) {
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (dist[nx] <= dist[x] + 1) continue;
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }
}

void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pii> edges(M + 1);
    for (int i = 1; i <= M; i++) cin >> edges[i].first >> edges[i].second;
    
    vector<bool> init(M + 1, true);

    vector<pii> query(Q);
    for (int i = 0; i < Q; i++) {
        char x; cin >> x;
        query[i].first = (x == 'E');
        cin >> query[i].second;
        if (!query[i].first) init[query[i].second] = false;
    }

    for (int i = 1; i <= M; i++) {
        if (init[i]) {
            auto& [u, v] = edges[i];
            E[u].push_back(v);
        }
    }

    for (int i = 1; i <= N; i++) dist[i] = inf;
    dist[1] = 0;
    update(1);

    reverse(query.begin(), query.end());

    vector<int> ret;

    for (auto& [t, p] : query) {
        if (!t) {
            auto& [u, v] = edges[p];
            E[u].push_back(v);
            update(u);
        }
        else {
            if (dist[p] == inf) ret.push_back(-1);
            else ret.push_back(dist[p]);
        }
    }

    reverse(ret.begin(), ret.end());

    for (int ans : ret) cout << ans << endl;





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