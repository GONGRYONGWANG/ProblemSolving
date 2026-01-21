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


int arr[5];
int dist[10001][5];
vector<pii> E[10001];

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) cin >> arr[i];

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    for (int i = 0; i < K; i++) {
        vector<bool> visited(N + 1, false);
        pq<pii, vector<pii>, cmp> q;
        q.push({ arr[i],0 });
        while (!q.empty()) {
            auto [x, d] = q.top();
            q.pop();
            if (visited[x]) continue;
            visited[x] = true;
            dist[x][i] = d;
            for (auto [nx, w] : E[x]) {
                if (visited[nx]) continue;
                q.push({ nx,d + w });
            }
        }
    }
    

    int ans = inf;

    for (int i = 1; i <= N; i++) {
        bool flag = false;
        vector<int> v(K);
        for (int j = 0; j < K; j++) {
            flag |= (i == arr[j]);
            v[j] = j;
        }
        if (flag) continue;
        
        do {
            int ret = dist[i][v.front()] + dist[i][v.back()];
            for (int j = 0; j < K - 1; j++) {
                ret += dist[arr[v[j + 1]]][v[j]];
            }

            ans = min(ans, ret);
        } while (next_permutation(v.begin(), v.end()));

    }

    cout << ans;



    // cout << "Case #" << tc << ": " << ret << endl;
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