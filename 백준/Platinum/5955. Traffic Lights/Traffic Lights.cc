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



//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

bool init[301];
int R[301];
int Dur[301][2];
vector<pii> E[301];
bool visited[301];

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

void solve() {
    int S, D;
    cin >> S >> D;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c >> R[i] >> Dur[i][0] >> Dur[i][1];
        init[i] = (c == 'P');
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    pq<pii, vector<pii>, cmp> q;
    q.push({ S,0 });
    while (!q.empty()) {
        int cur = q.top().first;
        int d = q.top().second;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (cur == D) {
            cout << d;
            return;
        }
        for (pii e : E[cur]) {
            int nx = e.first;
            if (init[cur] != init[nx] && R[cur] == R[nx] && Dur[cur][0] == Dur[nx][1] && Dur[cur][1] == Dur[nx][0]) continue;
            bool curcol, nxcol;

            if (d >= R[cur] && (d - R[cur]) % (Dur[cur][0] + Dur[cur][1]) < Dur[cur][!init[cur]]) curcol = !init[cur];
            else curcol = init[cur];

            if (d >= R[nx] && (d - R[nx]) % (Dur[nx][0] + Dur[nx][1]) < Dur[nx][!init[nx]]) nxcol = !init[nx];
            else nxcol = init[nx];

            if (curcol == nxcol) {
                q.push({ nx, e.second + d });
                continue;
            }

            vector<int> curchange, nxchange;
            if (d < R[cur]) {
                curchange.push_back(R[cur] - d);
                curchange.push_back(curchange.back() + Dur[cur][!init[cur]]);
                curchange.push_back(curchange.back() + Dur[cur][init[cur]]);
            }
            else {
                if ((d - R[cur]) % (Dur[cur][0] + Dur[cur][1]) < Dur[cur][!init[cur]]) {
                    curchange.push_back(Dur[cur][!init[cur]] - (d - R[cur]) % (Dur[cur][0] + Dur[cur][1]));
                    curchange.push_back(curchange.back() + Dur[cur][init[cur]]);
                    curchange.push_back(curchange.back() + Dur[cur][!init[cur]]);
                }
                else {
                    curchange.push_back(Dur[cur][0] + Dur[cur][1] - (d - R[cur]) % (Dur[cur][0] + Dur[cur][1]));
                    curchange.push_back(curchange.back() + Dur[cur][!init[cur]]);
                    curchange.push_back(curchange.back() + Dur[cur][init[cur]]);
                }
            }
            
            if (d < R[nx]) {
                nxchange.push_back(R[nx] - d);
                nxchange.push_back(nxchange.back() + Dur[nx][!init[nx]]);
                nxchange.push_back(nxchange.back() + Dur[nx][init[nx]]);
            }
            else {
                if ((d - R[nx]) % (Dur[nx][0] + Dur[nx][1]) < Dur[nx][!init[nx]]) {
                    nxchange.push_back(Dur[nx][!init[nx]] - (d - R[nx]) % (Dur[nx][0] + Dur[nx][1]));
                    nxchange.push_back(nxchange.back() + Dur[nx][init[nx]]);
                    nxchange.push_back(nxchange.back() + Dur[nx][!init[nx]]);
                }
                else {
                    nxchange.push_back(Dur[nx][0] + Dur[nx][1] - (d - R[nx]) % (Dur[nx][0] + Dur[nx][1]));
                    nxchange.push_back(nxchange.back() + Dur[nx][!init[nx]]);
                    nxchange.push_back(nxchange.back() + Dur[nx][init[nx]]);
                }
            }

            for (int i = 0; i < 3; i++) {
                if (curchange[i] != nxchange[i]) {
                    q.push({ nx, d + min(curchange[i],nxchange[i]) + e.second });
                    break;
                }
            }
        }
    }

    cout << 0;

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
