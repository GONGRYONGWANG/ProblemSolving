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
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const int inf = 1e9;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
//const double pi = 3.14159265358979323846;


pii parent[1001][1001];

pii find(pii a) {
    int x = a.first;
    int y = a.second;
    if (parent[x][y] == a) return a;
    return parent[x][y] = find(parent[a.first][a.second]);
}

void mer(pii a, pii b) {
    if (find(a) == find(b)) return;
    parent[find(b).first][find(b).second] = find(a);
}

bool board[1001][1001];
int sz[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            parent[i][j] = { i,j };
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!board[i][j]) continue;
            for (int dir = 0; dir < 4; dir++) {
                pii next = {i+dx[dir], j + dy[dir]};
                if (next.first<1 || next.first>N || next.second<1 || next.second>M || !board[next.first][next.second]) continue;
                mer({ i,j }, next);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!board[i][j]) continue;
            sz[find({ i,j }).first][find({ i,j }).second] += 1;
        }
    }


    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j]) continue;
            int ret = 1;
            set<pii> visited;
            for (int dir = 0; dir < 4; dir++) {
                pii next = { i + dx[dir], j + dy[dir] };
                if (next.first<1 || next.first>N || next.second<1 || next.second>M || !board[next.first][next.second] || visited.count(find(next))) continue;
                visited.insert(find(next));
                ret += sz[find(next).first][find(next).second];
            }
            ans = max(ans, ret);
        }
    }
    cout << ans;
    return 0;
}
