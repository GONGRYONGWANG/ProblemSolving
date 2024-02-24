//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18

//#2533
int N;
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
vector<int> edge[1000001];
int DP[1000001][2];
int parent[1000001];
int dp(int node, bool x) {
    if (DP[node][x] != 0) {
        return DP[node][x];
    }
    if (x) {
        DP[node][x] += 1;
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i] != parent[node]) {
                DP[node][x] += min(dp(edge[node][i], 0), dp(edge[node][i], 1));
            }
        }
    }
    else {
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i] != parent[node]) {
                DP[node][x] += dp(edge[node][i], 1);
            }
        }
    }
    return DP[node][x];
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i] != parent[node]) {
                parent[edge[node][i]] = node;
                Q.push(edge[node][i]);
            }
        }
    }

    cout << min(dp(1, 1), dp(1, 0));

    return 0;
}

