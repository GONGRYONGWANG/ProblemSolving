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


// F[];
ll factorial(ll x) {
    ll ret = 1;
    //ret = F[x];
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



int cnt[6][6][6][6][6][6];
int DP[6][6][6][6][6][6];
void solve() {
    int N;
    cin >> N;
    vector<vector<ll>> arr(N);
    for (int i = 0; i < N; i++) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        a = 6 - a; b = 6 - b; c = 6 - c; d = 6 - d; e = 6 - e; f = 6 - f;
        cnt[a][b][c][d][e][f] += 1;
        arr[i] = { a,b,c,d,e,f };
    }

    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 6; b++) {
            for (int c = 0; c < 6; c++) {
                for (int d = 0; d < 6; d++) {
                    for (int e = 0; e < 6; e++) {
                        for (int f = 0; f < 6; f++) {
                            for (int aa = a; aa < 6; aa++) {
                                for (int bb = b; bb < 6; bb++) {
                                    for (int cc = c; cc < 6; cc++) {
                                        for (int dd = d; dd < 6; dd++) {
                                            for (int ee = e; ee < 6; ee++) {
                                                for (int ff = f; ff < 6; ff++) {
                                                    DP[aa][bb][cc][dd][ee][ff] += cnt[a][b][c][d][e][f];
                                                }
                                            }
                                        }
                                    }
                                }
                            }


                        }
                    }
                }
            }
        }
    }

    int mx = 0;
    vector<int> ans;

    for (int i = 0; i < N; i++) {
        int a, b, c, d, e, f;
        a = arr[i][0];
        b = arr[i][1];
        c = arr[i][2];
        d = arr[i][3];
        e = arr[i][4];
        f = arr[i][5];
        if (N - DP[a][b][c][d][e][f] > mx) {
            mx = N - DP[a][b][c][d][e][f];
            ans.clear();
        }
        if (mx == N - DP[a][b][c][d][e][f]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << " " << mx << endl;
    for (int x : ans) {
        cout << x << " ";
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
