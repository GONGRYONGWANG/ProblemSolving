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

vector<int> E[100001];
vector<int> rE[100001];
unordered_map<int, int> Enum[100001];
int ret[100001];
bool ans[100001];
bool visited[100001];
void solve() {

    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        rE[v].push_back(u);
        Enum[u][v] = i;
    }
    fill(visited, visited + N + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int nx = E[x][i];
            if (visited[nx]) continue;
            visited[nx] = true;
            q.push(nx);
        }

        for (int i = 0; i < rE[x].size(); i++) {
            int nx = rE[x][i];
            if (visited[nx]) continue;
            visited[nx] = true;
            ret[1] += 1;
            q.push(nx);
        }
    }

    fill(visited, visited + N + 1, false);
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int nx = E[x][i];
            if (visited[nx]) continue;
            visited[nx] = true;
            q.push(nx);
            ret[nx] = ret[x] + 1;
        }

        for (int i = 0; i < rE[x].size(); i++) {
            int nx = rE[x][i];
            if (visited[nx]) continue;
            visited[nx] = true;
            q.push(nx);
            ret[nx] = ret[x] - 1;
        }
    }

    int idx = 1;
    for (int i = 1; i <= N; i++) {
        if (ret[i] < ret[idx]) {
            idx = i;
        }
    }

    fill(visited, visited + N + 1, false);
    q.push(idx);
    visited[idx] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int nx = E[x][i];
            if (visited[nx]) continue;
            ans[Enum[x][nx]] = 0;
            visited[nx] = true;
            q.push(nx);
        }

        for (int i = 0; i < rE[x].size(); i++) {
            int nx = rE[x][i];
            if (visited[nx]) continue;
            ans[Enum[nx][x]] = 1;
            visited[nx] = true;
            q.push(nx);
        }
    }
    for (int i = 1; i < N; i++) {
        cout << ans[i];
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