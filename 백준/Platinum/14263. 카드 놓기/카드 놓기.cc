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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

char board[50][50];
unordered_map<char, vector<int>> m; //mnx, mxx, mny, mxy
unordered_map<char, unordered_set<char>> E;
unordered_map<char, int> cnt;
void solve(int tc) {


    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            board[i][j] = x;
            if (x == '.') continue;
            if (!m.count(x)) m[x] = { inf,-inf, inf,-inf };
            m[x] = { min(m[x][0], i),max(m[x][1], i), min(m[x][2] , j), max(m[x][3],j) };
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        char x = it->first;
        vector<int> v = it->second;
        for (int i = v[0]; i <= v[1]; i++) {
            for (int j = v[2]; j <= v[3]; j++) {
                if (board[i][j] == x) continue;
                if (board[i][j] == '.') {
                    cout << -1;
                    return;
                }
                if (!E[x].count(board[i][j])) {
                    E[x].insert(board[i][j]);
                    cnt[board[i][j]] += 1;
                }
            }
        }
    }

    string ans = "";
    unordered_map<char, bool> visited;
    pq<char, vector<char>, greater<char>> q;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (cnt[it->first] == 0) q.push(it->first);
    }

    while (!q.empty()) {
        char x = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        ans += x;
        for (char nx : E[x]) {
            cnt[nx] -= 1;
            if (cnt[nx] == 0) q.push(nx);
        }
    }

    if (ans.length() != m.size()) {
        cout << -1;
        return;
    }
    cout << ans;
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