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




/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}
*/

//////////////////////////////////////////////////////////////////////////////////////

void solve() {
    int N;
    cin >> N;

    vector<int> m1, m2, w1, w2;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            m1.push_back(-x);
        }
        else m2.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            w1.push_back(-x);
        }
        else w2.push_back(x);
    }

    int ans = 0;

    sort(m1.begin(), m1.end());
    sort(w2.begin(), w2.end());
    int midx = 0;
    int widx = 0;
    while (midx < m1.size() && widx < w2.size()) {
        if (m1[midx] > w2[widx]) {
            ans += 1;
            midx += 1;
            widx += 1;
        }
        else midx += 1;
    }

    sort(m2.begin(), m2.end());
    sort(w1.begin(), w1.end());
    midx = 0;
    widx = 0;
    while (midx < m2.size() && widx < w1.size()) {
        if (m2[midx] < w1[widx]) {
            ans += 1;
            midx += 1;
            widx += 1;
        }
        else widx += 1;
    }

    cout << ans;


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }

    return 0;
}