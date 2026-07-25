#include<bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int N = n;
    vector<vector<int>> E(N+1);
    for(auto e : edge){
        int u = e[0]; int v=e[1];
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    int mx = 0;
    vector<int> dist(N+1,0);
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        mx = dist[x];
        for(int nx:E[x]){
            if(dist[nx]) continue;
            dist[nx] = dist[x]+1;
            q.push(nx);
        }
    }
    
    for(int i=1; i<=N;i++) answer+=(dist[i]==mx);
    
    
    return answer;
}