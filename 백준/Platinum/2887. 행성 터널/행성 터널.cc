//#pragma warning(disable:4996) 
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<utility>
#include<string>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int parent[100001];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
    if (find(a) == find(b)) return;
    parent[find(a)] = find(b);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pii> X, Y, Z;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        int x, y, z;
        cin >> x >> y >> z;
        X.push_back({x,i});
        Y.push_back({y,i});
        Z.push_back({z,i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    vector<vector<int>> E;
    for (int i = 1; i < N; i++) {
        E.push_back({ X[i].first - X[i - 1].first,X[i].second, X[i - 1].second });
        E.push_back({ Y[i].first - Y[i - 1].first,Y[i].second, Y[i - 1].second });
        E.push_back({ Z[i].first - Z[i - 1].first,Z[i].second, Z[i - 1].second });
    }
    sort(E.begin(), E.end());
    ll ans = 0;
    for (int i = 0; i < E.size(); i++) {
        int d = E[i][0];
        int u = E[i][1];
        int v = E[i][2];
        if (find(u) == find(v)) continue;
        ans += d;
        merge(u, v);
    }
    cout << ans;

    return 0;
}