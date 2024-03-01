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


// int arr[30] = { 0,1,2,1,2,3,1,2,3,2,1,2,2,2,3,1,2,3,2,3,2,2,3,3,3,2,3,3,3,4 };

void solve() {
    int N, M;
    cin >> N >> M;
    int d1, d2, d3, d4;
    cout << "? " << 1 << " " << 1 << endl << flush;
    cin >> d1;
    cout << "? " << 1 << " " << M << endl << flush;
    cin >> d3;
    cout << "? " << N << " " << 1 << endl << flush;
    cin >> d4;

    pii p1, p2;
    p1 = { 0,0 };
    p2 = { 0,0 };

    int xpy = d1 + 2;
    int xmy = d3 - M + 1;
    int x = (xpy + xmy) / 2;
    int y = (xpy - xmy) / 2;
    if ((xpy + xmy) % 2 == 0 && x >= 1 && x <= N && y >= 1 && y <= M) {
        p1 = { x,y };
    }

    xpy = d1 + 2;
    xmy = N - 1 - d4;
    x = (xpy + xmy) / 2;
    y = (xpy - xmy) / 2;
    if ((xpy + xmy) % 2 == 0 && x >= 1 && x <= N && y >= 1 && y <= M) {
        p2 = { x,y };
    }
    if (p1.first == 0) {
        cout << "! " << p2.first << " " << p2.second << endl << flush;
        return;
    }
    if (p2.first == 0) {
        cout << "! " << p1.first << " " << p1.second << endl << flush;
        return;
    }
    if (p1 == p2) {
        cout << "! " << p1.first << " " << p1.second << endl << flush;
        return;
    }

    cout << "? " << p1.first << " " << p1.second << endl << flush;
    int d;
    cin >> d;
    if (d == 0) {
        cout << "! " << p1.first << " " << p1.second << endl << flush;
        return;
    }
    else {
        cout << "! " << p2.first << " " << p2.second << endl << flush;
        return;
    }


}
//d1 = x-1+y-1  // x+y = d1+2
// d3 = x-1+M-y // x-y = d3-M+1
//d4 = N-x+y-1  // x-y = N-1-d4

//  x = (N+M-d2+d3+M-1)/2

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    cin >> T;
    // T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
