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
const double pi = 3.14159265358979323846;


int arr[502][502];
int visited[502][502];

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            arr[i][j] = inf;
        }
    }

    pii V, J;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visited[i][j] = -1;
            char c;
            cin >> c;
            if (c == 'V') V = { i,j };
            else if (c == 'J') J = { i,j };
            else if (c == '+') arr[i][j] = 0;
            arr[i][j] = min(arr[i][j], min(arr[i - 1][j], arr[i][j - 1]) + 1);
        }
    }
    for (int i = N; i >= 1; i--) {
        for (int j = M; j >= 1; j--) {
            arr[i][j]= min(arr[i][j], min(arr[i + 1][j], arr[i][j + 1]) + 1);
        }
    }
    
    pq<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ V.first,V.second, arr[V.first][V.second] });
    visited[V.first][V.second] = arr[V.first][V.second];
    while (!q.empty()) {
        vector<int> node = q.top();
        q.pop();
        int x = node[0];
        int y = node[1];
        int d = node[2];
        if (d < visited[x][y]) continue;
        if (x == J.first && y == J.second) {
            cout << d;
            return 0;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx, ny;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if (nx<1 || nx>N || ny<1 || ny>M|| visited[nx][ny] >= min(d,arr[nx][ny])) continue;
            visited[nx][ny] = min(d, arr[nx][ny]);
            q.push({ nx,ny,min(d,arr[nx][ny]) });
        }
    }

    return 0;
}