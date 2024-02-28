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
#include<complex> // complex number
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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

//////////////////////////////////////////////////////////////////////////////////////

bool board[1000][1000];
int visited[1000][1000];

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            visited[i][j] = -1;
        }
    }
    queue<vector<int>> q;
    q.push({ 0,0,0 });
    visited[0][0] = 0;
    while (!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        int x = node[0];
        int y = node[1];
        int t = node[2];
        if (!board[(x + 1) % N][y] && !board[(x + 2) % N][y] && visited[(x + 2) % N][y] == -1) {
            q.push({ (x + 2) % N,y,t + 1 });
            visited[(x + 2) % N][y] = t + 1;
        }
        if (y + 1 < M && !board[(x + 1) % N][y + 1] && visited[(x + 1) % N][y + 1] == -1) {
            q.push({ (x + 1) % N,y + 1,t + 1 });
            visited[(x + 1) % N][y + 1] = t + 1;
        }
    }
    int ans = inf;
    for (int i = 0; i < N; i++) {
        if (visited[i][M - 1] != -1) {
            int t = visited[i][M - 1];
            ans = min(ans, t + (i + 1 + N - t % N) % N);
        }
    }
    if (ans == inf) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }

}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
