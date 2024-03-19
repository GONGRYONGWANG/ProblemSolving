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


set<int> problem[100001];
unordered_map<int,int> diff;
set<pii> p;

void solve() {

    int N;
    cin >> N;


    for (int i = 0; i < N; i++) {
        int x, d;
        cin >> x >> d;
        problem[d].insert(x);
        diff[x] = d;
        p.insert({ d,x });
    }
    int M;
    cin >> M;
    while (M--) {
        string q;
        cin >> q;
        if (q == "add") {
            int x, d;
            cin >> x >> d;
            problem[d].insert(x);
            diff[x] = d;
            p.insert({ d,x });
        }
        else if (q == "solved") {
            int x ,d;
            cin >> x;
            d = diff[x];
            problem[d].erase(x);
            diff.erase(x);
            p.erase({ d,x });
        }
        else {
            int x;
            cin >> x;
            if (x == 1) {
                cout << (*(--p.end())).second << endl;
            }
            else {
                cout << (*(p.begin())).second << endl;
            }
        }
    }

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