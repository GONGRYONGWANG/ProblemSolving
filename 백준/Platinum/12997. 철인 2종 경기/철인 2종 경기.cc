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

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

//////////////////////////////////////////////////////////////////////////////////////


int val[10001];
vector<int> v[10001];

void solve() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int s, r;
        cin >> s >> r;
        if (r > val[s]) {
            val[s] = r;
            v[s].clear();
            v[s].push_back(i);
        }
        else if (r == val[s]) {
            v[s].push_back(i);
        }
    }

    int mxr = 0;

    vector<pll> can;

    for(int i=10000;i>=1;i--){
        if (val[i] > mxr) {
            mxr = val[i];
            can.push_back({ i,val[i] });
        }
    }
    sort(can.begin(), can.end());

    vector<int> ans;

    for (int i = 0; i < can.size(); i++) {
        ll s2 = can[i].first;
        ll r2 = can[i].second;

        pll left = {0,0};
        for (int j = 0; j < i; j++) {
            ll s1, r1;
            s1 = can[j].first;
            r1 = can[j].second;
            pll ret = { s1 * (r1 - r2), (s2 - s1) * r1 };
            if (j == 0) {
                left = ret;
                continue;
            }
            if (ret.first * left.second > left.first * ret.second) left = ret;
        }

        pll right = { 0,0 };
        for (int j = i + 1; j < can.size(); j++) {
            ll s3, r3;
            s3 = can[j].first;
            r3 = can[j].second;
            pll ret = { s3 * (r2 - r3), (s3 - s2) * r3 };
            if (j == i + 1) {
                right = ret;
                continue;
            }
            if (ret.first * left.second < left.first * ret.second) right = ret;
        }

        if (i==0 || i==can.size()-1 || left.first * right.second <= right.first * left.second) {
            for (int j = 0; j < v[s2].size(); j++) {
                ans.push_back(v[s2][j]);
            }
        }

    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

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
