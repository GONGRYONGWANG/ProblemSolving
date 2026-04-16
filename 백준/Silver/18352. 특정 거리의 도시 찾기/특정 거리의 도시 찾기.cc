//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18

#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
int N, M, K, X;
bool visited[300001];
vector<int> line[300001];
vector<int> ans;
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> Q;
void dijkstra() {
    Q.push({ X,0 });
    while (!Q.empty()) {
        int node = Q.top().first;
        if (visited[node]) { Q.pop(); continue; }
        visited[node] = 1;
        int dist = Q.top().second;
        if (dist == K) { ans.push_back(node); Q.pop(); continue; }
        if (dist > K) { Q.pop(); continue; }
        for (int i = 0; i < line[node].size(); i++) {
            if (!visited[line[node][i]]) {
                Q.push({ line[node][i], dist + 1 });
            }
        }
        Q.pop();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N>> M >> K >> X;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        line[a].push_back(b);
    }
    dijkstra();
    if (ans.size() == 0) {
        cout << -1;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}

