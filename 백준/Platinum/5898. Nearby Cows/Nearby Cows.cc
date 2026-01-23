#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> E[100001];
int DP[100001][21];
int parent[100001];


int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int N,K;
    cin>>N>>K;
    for(int i=0; i<N-1; i++){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int nx:E[x]){
            if(nx == parent[x]) continue;
            parent[nx] =x;
            q.push(nx);
        }
    }
    
    for(int i=1; i<=N;i++){
        int x; cin>>x;
        int idx = i;
        int k = K;
        while (idx!=0 && k >= 0){
            DP[idx][k] += x;
            if(k>=2 && idx!=1) DP[idx][k-2] -= x;
            k -=1;
            idx= parent[idx];
        }
    }
    
    q.push(1);
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int nx:E[x]){
            if(nx==parent[x]) continue;
            for(int j=1; j<=K; j++ ){
                DP[nx][j-1] += DP[x][j];
            }
            q.push(nx);
        }
    }

    for(int i=1; i<=N;i++){
        int ret= 0;
        for(int j=0; j<=K; j++) ret += DP[i][j];
        cout<<ret<<endl;
    }
    

    return 0;
}
