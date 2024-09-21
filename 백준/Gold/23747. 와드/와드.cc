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
#include<fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";

int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

char board[1000][1000];
pii parent[1000][1000];
pii findp(pii x) {
    if (parent[x.first][x.second] == x) return x;
    return parent[x.first][x.second] = findp(parent[x.first][x.second]);
}

struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            parent[i][j] = { i,j };
            cin >> board[i][j];
            if (i != 0 && board[i][j] == board[i - 1][j]) {
                parent[findp({ i - 1,j }).first][findp({ i - 1,j }).second] = { i,j };
            }
            if (j != 0 && board[i][j] == board[i][j - 1]) {
                parent[findp({ i,j - 1 }).first][findp({ i,j - 1 }).second] = { i,j };
            }
        }
    }

    unordered_set<pii, PiiHasher> st;
    int x, y;
    cin >> x >> y;
    x -= 1; y -= 1;
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'W') st.insert(findp({ x,y }));
        else if (c == 'U') x -= 1;
        else if (c == 'D') x += 1;
        else if (c == 'L') y -= 1;
        else y += 1;
    }
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool b = false;
            if (i == x && j == y) b = true;
            for (int dir = 0; dir < 4; dir++) {
                int nx, ny;
                nx = i + dx[dir]; ny = j + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (nx==x && ny==y) b = true;
            }
            if (b) {
                cout << ".";
                continue;
            }
            if (st.count(findp({ i,j }))) {
                cout << ".";
            }
            else cout << "#";
        }
        cout << endl;
    }





}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
