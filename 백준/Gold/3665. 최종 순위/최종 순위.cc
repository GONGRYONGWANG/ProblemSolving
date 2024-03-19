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

bool procede[501][501];
void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            procede[arr[i]][arr[j]] = true;
        }
        for (int j = i + 1; j < N; j++) {
            procede[arr[i]][arr[j]] = false;
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        swap(procede[a][b], procede[b][a]);
    }

    queue<int> q;

    vector<int> cnt(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (procede[i][j]) cnt[i] += 1;
        }
        if (cnt[i] == 0) q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        if (q.size() != 1) {
            cout << "?" << endl;
            return;
        }
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int i = 1; i <= N; i++) {
            if (!procede[i][cur]) continue;
            cnt[i] -= 1;
            if (cnt[i] == 0) q.push(i);
        }
    }

    if (ans.size() != N) cout << "IMPOSSIBLE";
    else {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
    }
    cout << endl;



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