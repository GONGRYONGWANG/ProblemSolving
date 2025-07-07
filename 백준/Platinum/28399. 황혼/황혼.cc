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
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
///////////////////////////////////////////////////////////////

struct cmp {
    bool operator()(vector<ll>& a, vector<ll>& b) {
        return a[2] > b[2];
    }
};

vector<pll> E[200001];
ll dist[200001][2];
bool visited[200001][2];
int prv[200001];
bool isend[200001];

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;
    while (M--) {
        ll u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
    }

    while (K--) {
        int s;
        cin >> s;
        int p = 0;
        while (s--) {
            int x; cin >> x;
            prv[x] = p;
            p = x;
        }
        isend[p] = true;
    }

    pq<vector<ll>, vector<vector<ll>>, cmp> q;
    q.push({ 1,!prv[1],0 });
    while (!q.empty()) {
        int x = q.top()[0]; bool b = q.top()[1];
        ll d = q.top()[2];
        q.pop();
        if (visited[x][b]) continue;
        visited[x][b] = true;
        dist[x][b] = d;
        for (pll& e : E[x]) {
            int nx = e.first; ll nd = d + e.second;
            bool nb = false;
            if (prv[nx] == 0 || (b && prv[nx] == x)) nb = true;
            if (visited[nx][nb]) continue;
            if (nb && isend[nx]) continue;
            q.push({ nx,nb,nd });
        }
    }

    for (int i = 1; i <= N; i++) {
        ll ret = INF;
        if (visited[i][0]) ret = min(ret, dist[i][0]);
        if (visited[i][1]) ret = min(ret, dist[i][1]);
        if (ret == INF) cout << -1;
        else cout << ret;
        cout << " ";
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