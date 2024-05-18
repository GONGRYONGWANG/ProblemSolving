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

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

vector<pii> E[1002];
void solve() {
    int R, C;
    cin >> R >> C;
    int N;
    cin >> N;
    vector<vector<int>> arr;
    vector<int> og_cnt(N+2, 0);
    arr.push_back({ 1,1,0 });
    for (int i = 1; i <= N; i++){
        int r, c, f;
        cin >> r >> c >> f;
        arr.push_back({ r,c,f });
    }
    arr.push_back({ R,C,0 });

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            if (i == j) continue;
            if (arr[i][0] <= arr[j][0] && arr[i][1] <= arr[j][1]) {
                E[i].push_back({ j, arr[i][2] - arr[j][0] + arr[i][0] - arr[j][1] + arr[i][1] });
                og_cnt[j] += 1;
            }
        }
    }


    int l = 0;
    int r = 6000;
    while (l < r) {
        int m = (l + r) / 2;
        vector<int> DP(N + 2, -inf);
        vector<int> cnt = og_cnt;
        queue<int> q;
        q.push(0);
        DP[0] = m;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (pii e : E[cur]) {
                if (DP[cur] + e.second >= 0) {
                    DP[e.first] = max(DP[e.first], DP[cur] + e.second);
                }
                cnt[e.first] -= 1;
                if (cnt[e.first] == 0) {
                    q.push(e.first);
                }
            }
        }
        if (DP[N + 1] >= 0) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    cout << l;



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
