//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

bool con(vector<int> a, vector<int> b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) <= (a[2] + b[2]) * (a[2] + b[2]);
}

bool cmp(vector<int> a, vector<int> b) {
    return a[0] - a[2] < b[0] - b[2];
}

vector<vector<int>> point;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    if (find(a) == find(b)) return;
    a = find(a);
    b = find(b);
    parent[b] = a;
    return;
}

void solve() {
    int N;
    cin >> N;
    point.clear();
    parent.clear();
    for (int i = 0; i < N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        point.push_back({ x,y,r });
        parent.push_back(i);
    }
    sort(point.begin(), point.end(), cmp);
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (point[i][0] + point[i][2] < point[j][0] - point[j][2]) break;
            if (con(point[i], point[j])) merge(i, j);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (find(i) == i) ans += 1;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}