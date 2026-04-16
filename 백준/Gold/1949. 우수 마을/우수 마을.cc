//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18

int N;
int citizen[10001];
int DP[10001][2];
#include<vector>
#include<queue>
#include<algorithm>
vector<int> edge[10001];
int parent[10001];
int dp(int node, bool x) {
    if (DP[node][x] != 0) {
        return DP[node][x];
    }
    if (x) {
        DP[node][x] += citizen[node];
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i]!= parent[node]) {
                DP[node][x] += dp(edge[node][i], 0);
            }
        }
    }
    else {
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i] != parent[node]) {
                DP[node][x] += max(dp(edge[node][i], 1), dp(edge[node][i], 0));
            }
        }
    }
    return DP[node][x];
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> citizen[i];
    }
    int u, v;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int node = Q.front();
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i] != parent[node]) {
                parent[edge[node][i]] = node;
                Q.push(edge[node][i]);
            }
        }
        Q.pop();
    }
    cout << max(dp(1, 0), dp(1, 1));
    return 0;
}

