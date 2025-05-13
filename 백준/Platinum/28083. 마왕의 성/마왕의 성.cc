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
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


ll h[1000][1000];
ll c[1000][1000];
pii parent[1000][1000];
pii findp(pii p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}

void mer(pii a, pii b) {
    a = findp(a); b = findp(b);
    if (a == b) return;
    c[a.first][a.second] += c[b.first][b.second];
    parent[b.first][b.second] = a;
}

ll ret[1000][1000];

void solve(int tc) {
    
    int N, M;
    cin >> N >> M;

    map<ll, vector<pii>> m;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> h[i][j];
            m[h[i][j]].push_back({ i,j });
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c[i][j];
            parent[i][j] = { i,j };
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        ll height = it->first;
        for (auto [x,y] : it->second) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir]; int ny = y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (h[nx][ny] > height) continue;
                mer({ x,y }, { nx,ny });
            }
        }
        for (auto [x, y] : it->second) ret[x][y] = c[findp({ x,y }).first][findp({ x,y }).second];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
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