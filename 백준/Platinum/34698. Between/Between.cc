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


int dist[2001][2001];
vector<int> E[2001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nx : E[x]) {
                if (dist[i][nx] != inf) continue;
                dist[i][nx] = dist[i][x] + 1;
                q.push(nx);
            }
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int a, b, k;
        cin >> a >> b >> k;
        vector<pii> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i].second;
            arr[i].first = dist[a][arr[i].second];
        }
        arr.push_back({ 0,a });
        sort(arr.begin(), arr.end());
        arr.push_back({ dist[a][b],b });

        bool flag = true;
        for (int i = 1; i < k + 2; i++) {
            flag &= (dist[arr[i - 1].second][arr[i].second] != inf);
            flag &= (arr[i].first != inf);
            flag &= (arr[i - 1].first + dist[arr[i - 1].second][arr[i].second] == arr[i].first);
        }

        cout << (flag ? "YES" : "NO") << endl;

    }











    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}