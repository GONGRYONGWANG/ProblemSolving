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

bool visited[201][201][201];

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    queue<vector<int>> q;
    q.push({ 0,0,C });
    visited[0][0][C] = true;
    while (!q.empty()) {
        int a, b, c;
        a = q.front()[0]; b = q.front()[1]; c = q.front()[2];
        q.pop();
        if (!visited[a - min(a, B - b)][b + min(a, B - b)][c]) {
            visited[a - min(a, B - b)][b + min(a, B - b)][c] = true;
            q.push({ a - min(a, B - b),b + min(a, B - b), c });
        }
        if (!visited[a - min(a, C - c)][b][c + min(a, C - c)]) {
            visited[a - min(a, C - c)][b][c + min(a, C - c)] = true;
            q.push({ a - min(a,C - c), b, c + min(a,C - c) });
        }
        if (!visited[a + min(b, A - a)][b - min(b, A - a)][c]) {
            visited[a + min(b, A - a)][b - min(b, A - a)][c] = true;
            q.push({ a + min(b,A - a), b - min(b,A - a), c });
        }
        if (!visited[a][b - min(b, C - c)][c + min(b, C - c)]) {
            visited[a][b - min(b, C - c)][c + min(b, C - c)] = true;
            q.push({ a,b - min(b,C - c),c + min(b,C - c) });
        }
        if (!visited[a + min(c, A - a)][b][c - min(c, A - a)]) {
            visited[a + min(c, A - a)][b][c - min(c, A - a)] = true;
            q.push({ a + min(c,A - a),b,c - min(c,A - a) });
        }
        if (!visited[a][b + min(c, B - b)][c - min(c, B - b)]) {
            visited[a][b + min(c, B - b)][c - min(c, B - b)];
            q.push({ a,b + min(c,B - b), c - min(c,B - b) });
        }
    }

    for (int i = 0; i <= C; i++) {
        if (!visited[0][C - i][i]) continue;
        cout << i << " ";
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