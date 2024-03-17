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

vector<pii> E[2001];
int visited[2001];
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[1] == b[1]) return a[2] < b[2];
        return a[1] > b[1];
    }
};

void solve() {

    int N, M, t;
    cin >> N >> M >> t;
    for (int i = 1; i <= N; i++) {
        E[i].clear();
        visited[i] = 0;
    }
    int s, g, h;
    cin >> s >> g >> h;
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        E[a].push_back({ b,d });
        E[b].push_back({ a,d });
    }
    pq<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ s,0,1 });
    while (!q.empty()) {
        vector<int> node = q.top();
        q.pop();
        int cur = node[0];
        int dist = node[1];
        int gh = node[2];
        if (visited[cur] != 0) continue;
        visited[cur] = gh;
        for (int i = 0; i < E[cur].size(); i++) {
            int nx = E[cur][i].first;
            int nd = E[cur][i].second + dist;
            int ngh = gh;
            if (cur == g && nx == h)  ngh += 1;
            if (cur == h && nx == g) ngh += 1;
            if (visited[nx] != 0) continue;
            q.push({ nx,nd,ngh });
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        if (visited[x] > 1) {
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
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