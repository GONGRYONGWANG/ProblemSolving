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

int arr[7];

void solve() {
    for (int i = 1; i <= 6; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    ans += arr[6];

    ans += arr[5];
    arr[1] -= arr[5] * 11;

    ans += arr[4];
    arr[2] -= arr[4] * 5;

    ans += arr[3] / 4;
    arr[3] %= 4;
    ans += 1;
    if (arr[3] == 1) {
        arr[2] -= 5;
        arr[1] -= 7;
    }
    else if (arr[3] == 2) {
        arr[2] -= 3;
        arr[1] -= 6;
    }
    else if (arr[3] == 3) {
        arr[2] -= 1;
        arr[1] -= 5;
    }
    else {
        ans -= 1;
    }

    if (arr[2] < 0) {
        arr[1] -= (-arr[2]) * 4;
        arr[2] = 0;
    }

    ans += arr[2] / 9;
    arr[2] %= 9;
    if (arr[2] != 0) {
        ans += 1;
        arr[1] -= 36 - arr[2] * 4;
    }

    if (arr[1] < 0) arr[1] = 0;

    ans += arr[1] / 36;
    arr[1] %= 36;
    if (arr[1] != 0) {
        ans += 1;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}