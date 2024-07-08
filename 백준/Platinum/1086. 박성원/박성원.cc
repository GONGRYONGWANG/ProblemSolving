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
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
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

int N;
int K;
int digitmod[751];
int arrmod[15];
ll DP[32768][100];
ll len[32768];
string arr[15];

ll dp(int x, int r) {
    if (DP[x][r] != -1) return DP[x][r];
    if (x == (1 << N) - 1) {
        if (r == 0) return DP[x][r] = 1;
        else return DP[x][r] = 0;
    }
    ll ret = 0;
    for (int i = 0; i < N; i++) {
        if (x & (1 << i)) continue;
        ret += dp(x + (1 << i), (r - arrmod[i] * digitmod[len[x + (1 << i)]]%K + K) % K);
    }
    return DP[x][r] = ret;
}


void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j < 32768; j++) {
            len[j] += arr[i].length();
            if (j & (1 << i)) len[j] -= arr[i].length();
        }
    }
    cin >> K;

    for (int i = 0; i < N; i++) {
        for (char x : arr[i]) {
            arrmod[i] *= 10;
            arrmod[i] += (x - '0');
            arrmod[i] %= K;
        }
    }

    digitmod[0] = 1;
    for (int i = 1; i <= 750; i++) {
        digitmod[i] = digitmod[i - 1] * 10 % K;
    }


    for (int i = 0; i < 32768; i++) {
        for (int j = 0; j < 100; j++) {
            DP[i][j] = -1;
        }
    }


    ll denom = 1;
    for (int i = 1; i <= N; i++) {
        denom *=i;
    }

    ll numer = dp(0, 0);



    if (numer == 0) {
        cout << "0/1";
        return;
    }

    ll g = gcd(numer, denom);
    cout << numer / g << "/" << denom / g;



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
