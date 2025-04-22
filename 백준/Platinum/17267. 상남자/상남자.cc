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
#define INF ll(9e18)
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

bool visited[1000][1000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    int L, R;
    cin >> L >> R;
    int sx, sy;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            visited[i][j] = (c == '1');
            if (c == '2') sx = i, sy = j;
        }
    }

    int ans = 0;

    deque<vector<int>> q;
    q.push_back({ sx,sy,0 });
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int r = q.front()[2];
        int l = sy + r - y;
        q.pop_front();
        if (r > R || l > L) continue;
        if (visited[x][y]) continue;
        visited[x][y] = true;
        ans += 1;
        if (x != 0 && !visited[x - 1][y]) {
            q.push_front({ x - 1,y,r });
        }
        if (x != N - 1 && !visited[x + 1][y]) {
            q.push_front({ x + 1,y, r });
        }
        if (y != 0 && !visited[x][y - 1] && l != L) {
            q.push_front({ x,y - 1,r });
        }
        if (y != M - 1 && !visited[x][y + 1] && r != R) {
            q.push_back({ x,y + 1,r + 1 });
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