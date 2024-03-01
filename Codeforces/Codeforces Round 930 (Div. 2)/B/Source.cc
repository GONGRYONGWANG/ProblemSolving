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

int board[2][200000];
int visit[2][200000];
bool visited[2][200000];

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0];
    }
};

void solve() {
    
    int N;
    cin >> N;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            board[i][j] = x - '0';
            visit[i][j] = 0;
            visited[i][j] = false;
        }
    }
    vector<int> arr(N+1, -1);
    visit[0][0] = 1;
    pq<vector<int>,vector<vector<int>>, cmp> q;
    q.push({ 0,board[0][0],0,0 });
    while (!q.empty()) {
        vector<int> v = q.top();
        q.pop();
        int t = v[0];
        int val = v[1];
        int x = v[2];
        int y = v[3];
        if (arr[t] != -1 && arr[t] < val) continue;
        if (visited[x][y]) continue;
        visited[x][y] = true;
        arr[t] = val;
        if (x != 1) {
            visit[1][y] += visit[x][y];
            q.push({ t + 1,board[1][y],1,y });
        }
        if (y != N - 1) {
            visit[x][y + 1] += visit[x][y];
            q.push({ t + 1,board[x][y + 1],x,y + 1 });
        }
    }
    for (int i = 0; i <= N; i++) {
        cout << arr[i];
    }
    cout << endl;
    cout << visit[1][N - 1] << endl;


}


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
