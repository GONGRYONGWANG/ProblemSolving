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


ll X[2001];
ll Y[2001];
ll R[2001];

bool cal(int a, int b) {

    return (abs(X[a] - X[b]) <= R[a] + R[b] && abs(Y[a] - Y[b]) <= R[a] + R[b]);
}

void solve(int tc) {

    int N;
    cin >> N;

    vector<pll> arr(N);
    for (int i = 0; i < N; i++) {
        ll x, y, r;
        cin >> x >> y >> r;
        X[i + 1] = x;
        Y[i + 1] = y;
        R[i + 1] = r;
        arr[i] = { r, i+1 };
    }

    sort(arr.rbegin(), arr.rend());

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int idx = arr[i].second;
        bool flag = false;
        for (int x : v) {
            if (cal(idx, x)) flag = true;
        }
        if (!flag) v.push_back(idx);
    }

    cout << v.size() << endl;
    for (int x : v) cout << x << endl;








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