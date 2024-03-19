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

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

void solve() {
    
    int N;
    cin >> N;
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        int s, d, p;
        cin >> s >> d >> p;
        arr[i] = { s,s + d,p };
    }
    sort(arr.begin(), arr.end(), cmp);

    map<int, int> m;
    m[0] = 0;
    for (int i = 0; i < N; i++) {
        int s = arr[i][0];
        int e = arr[i][1];
        int p = arr[i][2];
        m[e] = max((*(--m.upper_bound(e))).second, (*(--m.upper_bound(s))).second + p);
    }

    int ans = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        ans = max(ans, (*iter).second);
    }
    cout << ans << endl;


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    // T = 1;
    while (T--) {
        solve();
    }

    return 0;
}