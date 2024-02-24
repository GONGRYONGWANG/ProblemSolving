//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

vector<int> line[1001];
int N,M, V;
bool visited[1001];
void DFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < line[node].size(); i++) {
        if (!visited[line[node][i]]) {
            DFS(line[node][i]);
        }
    }
    return;
}

void BFS() {
    queue<int> Q;
    Q.push(V);
    while (!Q.empty()) {
        if (visited[Q.front()]) {
            Q.pop(); continue;
        }
        cout << Q.front() << " ";
        visited[Q.front()] = 1;
        for (int i = 0; i < line[Q.front()].size(); i++) {
            if (!visited[line[Q.front()][i]]) {
                Q.push(line[Q.front()][i]);
            }
        }
        Q.pop();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M >> V;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        sort(line[i].begin(), line[i].end());
    }
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    DFS(V);
    cout << endl;
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    BFS();
    return 0;
}

