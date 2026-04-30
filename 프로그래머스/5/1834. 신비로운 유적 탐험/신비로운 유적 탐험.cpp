#include<bits/stdc++.h>
using namespace std;


struct MCMF { // SPFA O(VEf) - Practically Ef
    struct Edge {
        int to, rev;
        long long cap, flow, cost;
        Edge(int to, int rev, long long cap, long long cost) : to(to), rev(rev), cap(cap), flow(0), cost(cost) {}
    };

    int n;
    vector<vector<Edge>> adj;
    vector<long long> dist;
    vector<int> parent, parentEdge;
    vector<bool> inQueue;
    int source, sink;

    MCMF(int n) : n(n), adj(n), dist(n), parent(n), parentEdge(n), inQueue(n), source(-1), sink(-1) {}

    void setSource(int s) {
        source = s;
    }

    void setSink(int t) {
        sink = t;
    }

    void addEdge(int u, int v, long long cap, long long cost, bool directed = true) {
        if (cap == 0) return;
        adj[u].emplace_back(v, adj[v].size(), cap, cost);
        adj[v].emplace_back(u, adj[u].size() - 1, 0, -cost); // 역방향 간선
        if (!directed) {
            adj[v].emplace_back(u, adj[u].size(), cap, cost);
            adj[u].emplace_back(v, adj[v].size() - 1, 0, -cost);
        }
    }

    bool spfa() {
        fill(dist.begin(), dist.end(), LLONG_MAX);
        fill(inQueue.begin(), inQueue.end(), false);
        queue<int> q;
        dist[source] = 0;
        inQueue[source] = true;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (int i = 0; i < adj[u].size(); ++i) {
                Edge& e = adj[u][i];
                if (e.flow < e.cap && dist[u] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[u] + e.cost;
                    parent[e.to] = u;
                    parentEdge[e.to] = i;

                    if (!inQueue[e.to]) {
                        inQueue[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }

        return dist[sink] != LLONG_MAX;
    }
    pair<long long, long long> get(int _source = -1, int _sink = -1) {
        if (_source != -1) {
            setSource(_source);
            setSink(_sink);
        }
        long long maxFlow = 0, minCost = 0;

        while (spfa()) {
            long long flow = LLONG_MAX;

            for (int u = sink; u != source; u = parent[u]) {
                Edge& e = adj[parent[u]][parentEdge[u]];
                flow = min(flow, e.cap - e.flow);
            }

            for (int u = sink; u != source; u = parent[u]) {
                Edge& e = adj[parent[u]][parentEdge[u]];
                e.flow += flow;
                adj[u][e.rev].flow -= flow;
                minCost += flow * e.cost;
            }

            maxFlow += flow;
        }
        return { maxFlow, minCost };
    }
};

vector<int> E1[101];
vector<int> E2[101];
int parent1[101];
int parent2[101];

int get(int x, int y){
    int ret= 1;
    vector<int> v1,v2;
    for(int nx:E1[x]){
        if(nx==parent1[x]) continue;
        v1.push_back(nx);
    }
    for(int nx:E2[y]){
        if(nx==parent2[y]) continue;
        v2.push_back(nx);
    }
    int n = v1.size(); int m = v2.size();
    MCMF graph(n+m+3);
    int src = n+m+1; int sink = n+m+2;
    for(int i=1; i<=n;i++){
        graph.addEdge(src,i,1,0);
    }
    for(int j=n+1; j<=n+m;j++){
        graph.addEdge(j,sink,1,0);
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            graph.addEdge(i+1,n+1+j,1, - get(v1[i],v2[j]));
        }
    }
    return 1 - graph.get(src,sink).second;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2) {
    int answer = 0;
    for(int i=1; i<=100;i++){
        E1[i].clear();
        E2[i].clear();
        parent1[i] = 0;
        parent2[i] = 0;
    }

    for(int i=0; i<n1-1; i++){
        int u= g1[i][0]; int v= g1[i][1];
        E1[u].push_back(v);
        E1[v].push_back(u);
    }
    for(int i=0; i<n2-1; i++){
        int u= g2[i][0]; int v= g2[i][1];
        E2[u].push_back(v);
        E2[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int nx:E1[x]){
            if(parent1[x]==nx) continue;
            parent1[nx] = x;
            q.push(nx);
        }
    }

    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int nx:E2[x]){
            if(parent2[x]==nx) continue;
            parent2[nx] = x;
            q.push(nx);
        }
    }



    answer = get(1,1);

    return answer;
}