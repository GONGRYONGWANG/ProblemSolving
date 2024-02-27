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
void solve() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    
    if (A * D > B * C) {
        swap(A, C);
        swap(B, D);
    }
    ll ans = INF;
    ll LCM = lcm(A,C);
    for (ll i = 0; i * A < LCM; i++) {
        if (i * A >= N) {
            ans = min(ans, i * B);
            break;
        }
        ll ret = i * B + (N - i * A) / C * D;
        if ((N - i * A) % C) ret += D;
        ans = min(ans, ret);
    }
    cout << ans;

}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}