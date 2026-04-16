#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>
#include<utility>
#include<queue>
vector<pair<pair<int, int>,int>> bus[1001]; 
int N , M;
int s, e;
int parent[1001];
int dist[1001];
bool visited[1001];
struct cmp {
    bool operator()(pair<pair<int, int>,int> a, pair<pair<int, int>,int> b) {
        return a.second > b.second;
    }
};

void dijkstra() {
    visited[s] = 1;
    priority_queue<pair<pair<int, int>,int>, vector<pair<pair<int, int>,int>>, cmp> Q;
    for (int i = 0; i < bus[s].size(); i++) {
        Q.push(bus[s][i]);
    }
    while (!Q.empty() && !visited[e]) {
        int node = Q.top().first.second;
        if (visited[node]) { Q.pop(); continue; }
        parent[node] = Q.top().first.first;
        dist[node] = Q.top().second;
        visited[node] = 1;
        Q.pop();
        for (int i = 0; i < bus[node].size(); i++) {
            if (!visited[bus[node][i].first.second]) {
                Q.push({ bus[node][i].first, bus[node][i].second + dist[node] });
            }
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        bus[a].push_back({ {a,b},c });
    }
    cin >> s >> e;
    dijkstra();
    int total = 0;
    int count = 1;
    vector<int> root;
    int node = e;
    while (node != s) {
        root.push_back(node);
        count++;
        node = parent[node];  
    }
    root.push_back(s);
    cout << dist[e] << endl;
    cout << count << endl;
    for (int i = root.size() - 1; i >= 0; i--) {
        cout << root[i]<<" ";
    }


    return 0;
}

