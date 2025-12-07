#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define endl "\n"

vector<ll> arr[2000];
int parent[2000];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

vector<pll> E[2000];

void solve(int tc) {


    int N;
    cin >> N;
        
    ll total = 0;

    for (int i = 0; i < N; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        arr[i] = { x,y,c };
        parent[i] = i;
        total -= c;
    }

    vector<tuple<ll, ll, ll>> edges;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            ll d = arr[i][2] + arr[j][2] + abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]);
            edges.push_back({ d,i,j });
        }
    }

    sort(edges.begin(), edges.end());

    for (auto [w, u, v] : edges) {
        u = findp(u); v = findp(v);
        if (u == v) continue;
        parent[u] = v;
        total += w;
    }

    for (int i = 0; i < N; i++) {
        cout << total + arr[i][2] << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}