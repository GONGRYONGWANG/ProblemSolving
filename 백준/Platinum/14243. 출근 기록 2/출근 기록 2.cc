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
    string s;
    cin >> s;
    int A, B, C;
    A = B = C = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') A += 1;
        else if (s[i] == 'B') B += 1;
        else C += 1;
    }

    string ans;

    char prv = 'A';
    char cur = 'A';
    for (int i = 0; i < s.length(); i++) {
        if (cur != 'B' && B >= C && B > 0) {
            ans.push_back('B');
            B -= 1;
            prv = cur;
            cur = 'B';
        }
        else if (prv != 'C' && cur != 'C' && C > 0) {
            ans.push_back('C');
            prv = cur;
            cur = 'C';
            C -= 1;
        }
        else if (A > 0) {
            ans.push_back('A');
            A -= 1;
            prv = cur;
            cur = 'A';
        }
        else {
            cout << -1;
            return;
        }
    }
    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1; //
    while (T--) {
        solve();
    }
    return 0;
}