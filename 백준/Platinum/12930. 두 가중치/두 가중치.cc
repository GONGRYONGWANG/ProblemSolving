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
#define INF ll(4e18+7)
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

pii adj[20][20];
bool visited[20][181];

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }
};

void solve(int tc) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            int d;
            if (x == '.') d = -1;
            else d = x - '0';
            adj[i][j].first = d;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            int d;
            if (x == '.') d = -1;
            else d = x - '0';
            adj[i][j].second = d;
        }
    }

    int ans = inf;

    pq<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int x = q.top()[0];
        int a = q.top()[1];
        int b = q.top()[2];
        q.pop();
        if (visited[x][a]) continue;
        visited[x][a] = true;
        if (x == 1) ans = min(ans, a * b);
        for (int nx = 0; nx < N; nx++) {
            auto [da, db] = adj[x][nx];
            if (da == -1) continue;
            if (a + da > 180) continue;
            if (visited[nx][a + da]) continue;
            q.push({ nx,a + da,b + db });
        }
    }

    if (ans == inf) cout << -1;
    else cout << ans;

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