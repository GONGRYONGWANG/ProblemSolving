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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

const string debug = "output: ";

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

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return powmod(x, mod - 2, mod);
}

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////


int h[25][25];
bool visited[25][25];

int dist[25][25];

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[2] > b[2];
    }
};

void solve() {
    int N, M, T, D;
    cin >> N >> M >> T >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = inf;
            char x;
            cin >> x;
            if (x < 'a') {
                h[i][j] = x - 'A';
            }
            else h[i][j] = x - 'a' + 26;
        }
    }

    pq<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int x = q.top()[0];
        int y = q.top()[1];
        int d = q.top()[2];
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        dist[x][y] = d;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd = d;

            if (nx < 0 || nx >= N || ny<0 || ny >= M || visited[nx][ny] || abs(h[x][y] - h[nx][ny]) > T) continue;

            if (h[x][y] >= h[nx][ny]) nd += 1;
            else nd += (h[nx][ny] - h[x][y]) * (h[nx][ny] - h[x][y]);

            q.push({ nx,ny, nd });
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }

    q.push({ 0,0,0 });
    while (!q.empty()) {
        int x = q.top()[0];
        int y = q.top()[1];
        int d = q.top()[2];
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        dist[x][y] += d;
        for(int dir=0; dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd = d;

            if (nx < 0 || nx >= N || ny<0 || ny >= M || visited[nx][ny] || abs(h[x][y] - h[nx][ny]) > T) continue;

            if (h[x][y] <= h[nx][ny]) nd += 1;
            else nd += (h[nx][ny] - h[x][y]) * (h[nx][ny] - h[x][y]);


            q.push({ nx,ny,nd });

        }

    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] > D) continue;
            ans = max(ans, h[i][j]);
        }
    }
    
    cout << ans;

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
