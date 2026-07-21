#include<bits/stdc++.h>
using namespace std;


int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    vector<vector<int>> adj(N+1,vector<int>(N+1,K+1));
    for(int i=1; i<=N;i++) adj[i][i] = 0;
    for(auto& r : road){
        int u = r[0]; int v =r[1];
        int w = r[2];
        adj[u][v] = adj[v][u] = min(adj[u][v], w);
    }
    
    for(int k=1; k<=N;k++){
        for(int i=1; i<=N;i++){
            for(int j=1;j<=N;j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N;i++){
        answer += (adj[1][i]<=K);
    }
    
    
    

    return answer;
}