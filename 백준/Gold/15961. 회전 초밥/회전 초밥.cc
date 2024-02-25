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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
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


int arr[6000000];
int ret = 0;
int cnt[3001];
void solve() {
    int N, D, K, C;
    cin >> N >> D >> K >> C;
    ret = 1;
    cnt[C] = 1;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i + N] = arr[i];
    }
    for (int i = 0; i < K; i++) {
        if (cnt[arr[i]] == 0) {
            ret += 1;
        }
        cnt[arr[i]] += 1;
    }
    int ans = ret;
    for (int i = K; i < 2*N; i++) {
        cnt[arr[i - K]] -= 1;
        if (cnt[arr[i - K]] == 0) {
            ret -= 1;
        }
        if (cnt[arr[i]] == 0) {
            ret += 1;
        }
        cnt[arr[i]] += 1;
        ans = max(ans, ret);
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