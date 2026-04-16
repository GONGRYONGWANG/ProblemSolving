//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18


//#2213

#include<vector>
#include<algorithm>
#include<queue>
int N;
int weight[10001];
vector<int> edge[10001];
pair<long long,vector<int>> DP[10001][2];

int parent[10001];

pair<long long, vector<int>> dp(int node, bool x) {
    if (DP[node][x].first != 0) {
        return DP[node][x];
    }
    vector<int> v;
    if (x) { 
        DP[node][x].first = weight[node]; 
        v.push_back(node);
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i] != parent[node]) {
                DP[node][x].first += dp(edge[node][i], 0).first;
                vector<int> tmp = dp(edge[node][i], 0).second;
                for (int j = 0; j < tmp.size(); j++) {
                    v.push_back(tmp[j]);
                }
            }
        }
    }
    else {
        for (int i = 0; i < edge[node].size(); i++) {
            if (edge[node][i] != parent[node]) {
                if (dp(edge[node][i], 1).first > dp(edge[node][i], 0).first) {
                    DP[node][x].first += dp(edge[node][i], 1).first;
                    vector<int> tmp = dp(edge[node][i], 1).second;
                    for (int j = 0; j < tmp.size(); j++) {
                        v.push_back(tmp[j]);
                    }
                }
                else {
                    DP[node][x].first += dp(edge[node][i], 0).first;
                    vector<int> tmp = dp(edge[node][i], 0).second;
                    for (int j = 0; j < tmp.size(); j++) {
                        v.push_back(tmp[j]);
                    }
                }
            }
        }
    }
    DP[node][x].second = v;
    return DP[node][x];
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
    }
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
    pair<long long, vector<int>> ans;
    ans = max(dp(1, 0), dp(1, 1));
    cout << ans.first << endl;
    sort(ans.second.begin(), ans.second.end());
    for (int i = 0; i < ans.second.size(); i++) {
        cout << ans.second[i] << " ";
    }
    return 0;
}

