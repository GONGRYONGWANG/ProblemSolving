#include<bits/stdc++.h>
using namespace std;

struct group{
    int front;
    int rear;
};

int parent[500000];
group* G[500000];
int idx[500000];
int nx[500000];
int prv[500000];
int findp(int x){
    if(parent[x]==x) return x;
    return parent[x] = findp(parent[x]);
}

vector<string> solution(int n, vector<vector<int>> queries) {
    vector<string> answer;
    
    int N = n;
    
    for(int i=0 ;i<N;i++){
        parent[i] = i;
        G[i] = new group{i,i};
        idx[i] = 0;
        nx[i] = -1;
        prv[i] = -1;
    }
    
    for(int i= 0 ; i<queries.size(); i++){
        vector<int> query = queries[i];
        int t = query[0];
        int x = query[1];
        int y = query[2];
        x = findp(x);
        y = findp(y);
        if(t==1){
            if(G[x]==G[y]) continue;
            int cur = G[y]->front;
            while(cur != -1){
                parent[cur] = y;
                cur = nx[cur];
            }
            prv[y] = G[x] ->rear;
            nx[y] = -1;
            nx[G[x]->rear] = y;
            G[x]->rear = y;
            G[y] = G[x];
            idx[y] = i+1;
        }
        else if(t==2){
            if(idx[x]>idx[y]) continue;
            
            if(prv[x]!=-1) nx[prv[x]] = nx[y];
            if(nx[y]!=-1) prv[nx[y]] = prv[x];
            if(G[x]->front == x) G[x]->front = nx[y];
            if(G[x]->rear == y) G[x]->rear = prv[x];
            
            prv[y] = nx[y] = -1;
            int cur = x;
            while(cur != nx[y]){
                parent[cur] = y;
                cur = nx[cur];
            }
            G[y] = new group{y,y};
            idx[y] = i+1;
        }
        else{
            answer.push_back((G[x]==G[y]) ? "Yes" : "No");
        }
        
    }
    
    
    
    return answer;
}