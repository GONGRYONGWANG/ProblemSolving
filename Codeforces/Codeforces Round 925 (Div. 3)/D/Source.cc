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


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

//////////////////////////////////////////////////////////////////////////////////////


void solve() {
    int N, x, y;
    cin >> N >> x >> y;
    map<int, map<ll,ll>> m;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        m[a % y][a % x] += 1;
    }

    ll ans = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        for (auto iter = (*it).second.begin(); iter != (*it).second.end(); iter++) {
            if ((*iter).first * 2 % x == 0) {
                ans += (*iter).second * ((*iter).second - 1);
            }
            else {
                (*it).second[(x - (*iter).first) % x];
                ans += (*iter).second * ((*it).second[(x - (*iter).first) % x]);
            }
        }
    }
    cout << ans / 2 << endl;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
