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

struct VectorHasher {
    size_t operator()(const vector<int>& V) const {
        size_t hash = V.size();
for (auto& i : V) {
    hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
}
return hash;
    }
};

struct PiiHasher {
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

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


//const ll Fsize = 1;
//ll F[Fsize];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x]; //
    return ret;
}

//ll modI[Fsize];  ll modIF[Fsize];
ll modinvfactorial(ll x) {
    ll ret = 1;
    //ret = modIF[x]; //
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    if (r == 0 || n == r) return 1;
    return factorial(n) * modinvfactorial(n - r) % mod * modinvfactorial(r) % mod;
}

ll ccw(pll a, pll b, pll c) {
    ll ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

bool intersect(pll A, pll B, pll C, pll D) { // 선분 교차 판정 A-B , C-D
    if (A > B) swap(A, B);
    if (C > D) swap(C, D);

    ll l1 = ccw(A, B, C) * ccw(A, B, D);
    ll l2 = ccw(C, D, A) * ccw(C, D, B);

    if (l1 == 0 && l2 == 0) {
        return A <= D && C <= B;
    }
    return l1 <= 0 && l2 <= 0;
}



int dx[4] = { 1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////


bool visited[2000][2000][4];
int board[2000][2000];

void solve() {
    int N, M;
    cin >> N >> M;
    queue<vector<int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                q.push({ i,j,0 });
                visited[i][j][0] = true;
                q.push({ i,j,1 });
                visited[i][j][1] = true;
                board[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        q.pop();

        if (board[x][y] == 0) {
            if (!visited[x][y][(d + 2) % 4]) {
                visited[x][y][(d + 2) % 4] = true;
                q.push({ x,y,(d + 2) % 4 });
            }
        }
        else if (board[x][y] == 1) {
            if (d == 0 || d == 2) {
                int nd = (d + 2) % 4;
                if (!visited[x][y][nd]) {
                    visited[x][y][nd] = true;
                    q.push({ x,y,nd });
                }
            }
        }
        else if (board[x][y] == 2) {
            if (d == 1 || d == 3) {
                int nd = (d + 2) % 4;
                if (!visited[x][y][nd]) {
                    visited[x][y][nd] = true;
                    q.push({ x,y,nd });
                }
            }
        }
        else if (board[x][y] == 3) {
            if (d == 0 && !visited[x][y][1]) {
                visited[x][y][1] = true;
                q.push({ x,y,1 });
            }
            if (d == 1 && !visited[x][y][0]) {
                visited[x][y][0] = true;
                q.push({ x,y,0 });
            }
            if (d == 2 && !visited[x][y][3]) {
                visited[x][y][3] = true;
                q.push({ x,y,3 });
            }
            if (d == 3 && !visited[x][y][2]) {
                visited[x][y][2] = true;
                q.push({ x,y,2 });
            }
        }
        else {
            if (d == 0 && !visited[x][y][3]) {
                visited[x][y][3] = true;
                q.push({ x,y,3 });
            }
            if (d == 3 && !visited[x][y][0]) {
                visited[x][y][0] = true;
                q.push({ x,y,0 });
            }
            if (d == 2 && !visited[x][y][1]) {
                visited[x][y][1] = true;
                q.push({ x,y,1 });
            }
            if (d == 1 && !visited[x][y][2]) {
                visited[x][y][2] = true;
                q.push({ x,y,2 });
            }
        }


        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny][(d + 2) % 4]) {
            visited[nx][ny][(d + 2) % 4] = true;
            q.push({ nx,ny,(d + 2) % 4 });
        }


    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool ret = 0;
            for (int d = 0; d < 4; d++) {
                ret |= visited[i][j][d];
            }
            if (ret) ans += 1;
        }
    }

    cout << ans;


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
