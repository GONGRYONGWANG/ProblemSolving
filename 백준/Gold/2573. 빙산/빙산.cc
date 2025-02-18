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

pair<short,short> parent[300][300];
pair<short,short> findp(pair<short,short> p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}

short board[300][300];
short T[300][300];
bool inq[300][300];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j]) T[i][j] = 1000;
            else T[i][j] = 0;
            parent[i][j] = { i,j };
        }
    }

    queue<pair<short,short>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j]) continue;
            for (int dir = 0; dir < 4; dir++) {
                short nx = i + dx[dir]; short ny = j + dy[dir];
                if (!board[nx][ny]) {
                    q.push({ i,j });
                    inq[i][j] = true;
                    break;
                }
            }
        }
    }

    vector<pair<short, vector<pair<short,short>>>> v;

    int t = 0;
    while (!q.empty()) {
        t += 1;
        queue<pair<short,short>> nq;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                if (T[nx][ny] < t) board[x][y] -= 1;
            }
            if (board[x][y] <= 0) {
                T[x][y] = t;
                if (v.empty() || v.back().first != t) {
                    v.push_back({ t,{} });
                }
                v.back().second.push_back({ x,y });
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir]; int ny = y + dy[dir];
                    if (board[nx][ny] && !inq[nx][ny]) {
                        nq.push({ nx,ny });
                        inq[nx][ny] = true;
                    }
                }
            }
            else nq.push({ x,y });
        }
        q = nq;
    }
    
    int ans = inf;
    for (auto it = prev(v.end()); ; it--) {
        for (auto [x, y] : it->second) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                if (T[nx][ny] >= T[x][y]) {
                    parent[findp({ nx,ny }).first][findp({ nx,ny }).second] = findp({ x,y });
                }
            }
        }
        for (auto [x, y] : it->second) {
            if (findp({ x,y }) != findp((it->second).front())) {
                if (it == v.begin()) ans = 0;
                else ans = prev(it)->first;
                break;
            }
        }
        if (it == v.begin()) break;
    }

    if (ans == inf) cout << 0;
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