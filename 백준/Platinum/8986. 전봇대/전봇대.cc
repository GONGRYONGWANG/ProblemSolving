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

string debug = "ans: ";

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


int N;
ll arr[100000];

ll get(ll x) {
    ll ret = 0;
    for (int i = 0; i < N; i++) {
        ret += abs(x * i - arr[i]);
    }
    return ret;
}

void solve() {
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ll l = 0;
    ll r = 1000000000;
    while(r-l>=3) {
        ll p = (2 * l + r) / 3;
        ll q = (l + 2 * r) / 3;
        if (get(p) > get(q)) {
            l = p;
        }
        else r = q;
    }
    ll ans = INF;
    for (ll i = l; i <= r; i++) {
        ans = min(ans, get(i));
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