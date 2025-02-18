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


int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

vector<pair<short,short>> E[1001][1001];
vector<pair<short,short>> rE[1001][1001];
int dists[1001][1001];
int diste[1001][1001];

void solve(int tc) {
    int N, M;
    cin >> N >> M;
    pair<short,short> s, e;
    cin >> s.first >> s.second >> e.first >> e.second;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int a; cin >> a;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir] * a; int ny = j + dy[dir] * a;
                if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
                E[i][j].push_back({ nx,ny });
                rE[nx][ny].push_back({ i,j });
            }
            dists[i][j] = diste[i][j] = inf;
        }
    }

    queue<pii> q;
    q.push(s);
    dists[s.first][s.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [nx, ny] : E[x][y]) {
            if (dists[nx][ny] != inf) continue;
            dists[nx][ny] = dists[x][y] + 1;
            q.push({ nx,ny });
        }
    }

    q.push(e);
    diste[e.first][e.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [nx, ny] : rE[x][y]) {
            if (diste[nx][ny] != inf) continue;
            diste[nx][ny] = diste[x][y] + 1;
            q.push({ nx,ny });
        }
    }

    int ans = inf;

    for (int i = 1; i <= N; i++) {
        int mns = inf; int mne = inf;
        for (int j = 1; j <= M; j++) {
            mns = min(mns, dists[i][j]);
            mne = min(mne, diste[i][j]);

            ans = min(ans, dists[i][j] + diste[i][j]);
        }
        ans = min(ans, mns + mne + 1);
    }
    for (int j = 1; j <= M; j++) {
        int mns = inf; int mne = inf;
        for (int i = 1; i <= N; i++) {
            mns = min(mns, dists[i][j]);
            mne = min(mne, diste[i][j]);
        }
        ans = min(ans, mns + mne + 1);
    }

    if (ans == inf) cout << -1;
    else cout << ans;


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}