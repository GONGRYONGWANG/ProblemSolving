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

int arr[1001][1001];
bool visited[1001][1001];

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    pq<vector<int>, vector<vector<int>>, cmp> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (i == 1 || i == N || j == 1 || j == M) {
                q.push({ i,j,arr[i][j] });
                visited[i][j] = true;
            }
        }
    }
    int K;
    cin >> K;
    while (K--) {
        vector<int> node = q.top();
        q.pop();
        int x, y;
        x = node[0]; y = node[1];
        cout << x << " " << y << endl;
        for (int dir = 0; dir < 4; dir++) {
            int nx, ny;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if (nx<1 || nx>N || ny < 1 || ny>M || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({ nx,ny,arr[nx][ny] });
        }
    }


    return 0;
}