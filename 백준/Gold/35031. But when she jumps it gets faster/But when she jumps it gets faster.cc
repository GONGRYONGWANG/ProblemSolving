#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


void solve(int tc) {

    ll N, L, K;
    cin >> N >> L >> K;

    vector<ll> arr(K);
    for (ll& x : arr) {
        cin >> x;
        x -= 1;
    }
    for (int i = 0; i < K; i++) {
        arr.push_back(arr[i] + L);
    }

    ll t = 0;
    ll idx = 0;
    ll v = 1;
    while (idx / L < N) {
        ll i = idx % L;
        auto it = lower_bound(arr.begin(), arr.end(), i);

        if (i + v - 1 >= *it || idx / L == N - 1) {
            t += 1;
            idx += v;
            ll d = v % L;
            v += v / L * K;
            if (d != 0) v += upper_bound(arr.begin(), arr.end(), i + d - 1) - lower_bound(arr.begin(), arr.end(), i);
        }
        else {
            ll d = *it - i + 1;
            t += (d + v - 1) / v - 1;
            idx += ((d + v - 1) / v - 1) * v;
        }
    }

    cout << t;

}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}