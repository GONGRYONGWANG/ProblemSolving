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

struct VectorHasher {
    int operator()(const vector<int>& V) const {
        int hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
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

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

int ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////


bool board[2000][2000];

void solve() {

    int N, M, K;
    cin >> N >> M >> K;
    

    vector<int> row(N, 0);
    vector<int> col(M, 0);

    int total = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                total += 1;
                row[i] += 1;
                col[j] += 1;
            }
        }
    }

    if (total == K) {
        cout << K << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j]) {
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
        return;
    }


    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (!board[x][y]) continue;
            bool a = false;
            bool b = false;
            if (x - 1 >= 0 && board[x - 1][y]) a = true;
            if (x + 1 < N && board[x + 1][y]) a = true;
            if (y - 1 >= 0 && board[x][y - 1]) b = true;
            if (y + 1 < M && board[x][y + 1]) b = true;

            if (a && b && total== 2*K-1) {
                cout << 1 << endl;
                cout << x+1 << " " << y+1;
                return;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (row[i] <= K) continue;
        cout << 2 * K - row[i] << endl;
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                for(int k = j+(row[i]-K); k< j + K;k++){
                    cout << i + 1 << " " << k+ 1 << endl;
                }
                return;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (col[i] <= K) continue;
        cout << 2 * K - col[i] << endl;
        for (int j = 0; j < M; j++) {
            if (board[j][i]) {
                for (int k = j + (col[i] - K); k < j + K; k++) {
                    cout << j + 1 << " " << k + 1 << endl;
                }
                return;
            }
        }
    }

    cout << 0;



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
