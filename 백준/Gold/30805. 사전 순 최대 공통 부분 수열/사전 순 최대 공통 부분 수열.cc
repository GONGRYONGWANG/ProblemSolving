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



int cntA[101][101];
int cntB[101][101];

void solve() {
    int N, M;
    cin >> N;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 0; j <= 100; j++) {
            cntA[i][j] = cntA[i - 1][j];
        }
        cntA[i][A[i]] += 1;
    }

    cin >> M;
    vector<int> B(M + 1);
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        for (int j = 0; j <= 100; j++) {
            cntB[i][j] = cntB[i - 1][j];
        }
        cntB[i][B[i]] += 1;
    }


    vector<int> ans;
    int aidx = 1; int bidx = 1;
    while (aidx <= N && bidx <= M) {
        bool b = false;
        for (int j = 100; j >= 1; j--) {
            if (cntA[N][j] - cntA[aidx - 1][j] != 0 && cntB[M][j] - cntB[bidx - 1][j] != 0) {
                ans.push_back(j);
                while (A[aidx] != j) aidx += 1;
                while (B[bidx] != j) bidx += 1;
                aidx += 1; bidx += 1;
                b = true;
                break;
            }
        }
        if (!b) break;
    }
    cout << ans.size() << endl;
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
