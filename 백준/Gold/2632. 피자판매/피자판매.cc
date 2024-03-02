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


ll A[1000001];
ll B[1000001];
int psuma[1001];
int psumb[1001];

void solve() {
    int S;
    cin >> S;
    int M, N;
    cin >> M >> N;

    int totala = 0;
    int totalb = 0;

    for (int i = 1; i <= M; i++) {
        cin >> psuma[i];
        totala += psuma[i];
        psuma[i] += psuma[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        cin >> psumb[i];
        totalb += psumb[i];
        psumb[i] += psumb[i - 1];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < i; j++) {
            A[psuma[i] - psuma[j]] += 1;
        }
    }
    for (int i = 2; i <= M - 1; i++) {
        for (int j = 1; j < i; j++) {
            A[totala - psuma[i] + psuma[j]] += 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            B[psumb[i] - psumb[j]] += 1;
        }
    }
    for (int i = 2; i <= N - 1; i++) {
        for (int j = 1; j < i; j++) {
            B[totalb - psumb[i] + psumb[j]] += 1;
        }
    }

    A[0] = B[0] = 1;

    ll ans = 0;
    for (int i = 0; i <= S; i++) {
        ans += A[i] * B[S - i];
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