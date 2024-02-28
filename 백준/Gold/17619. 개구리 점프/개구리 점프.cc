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

//////////////////////////////////////////////////////////////////////////////////////

int parent[100001];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void mer(int a, int b) {
    if (find(a) == find(b)) return;
    parent[find(b)] = find(a);
}


void solve() {
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr;
    for (int i = 1; i <= N; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        parent[i] = i;
        arr.push_back({ x1,x2,i });
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N - 1; i++) {
        if (arr[i][1] >= arr[i + 1][0]) {
            mer(arr[i][2], arr[i + 1][2]);
            arr[i + 1][1] = max(arr[i + 1][1], arr[i][1]);
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << 1;
        }
        else cout << 0;
        cout << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1; //
    while (T--) {
        solve();
    }
    return 0;
}