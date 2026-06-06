#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

bool visited[1001][1<<10];

struct cmp{
    bool operator()(vector<int>& A, vector<int>& B){
        return A[2]>B[2];
    }
};

vector<pii> E[1001];
vector<pii> rE[1001];
int istrap[1001];

bool isrv(int x, int bit){
    if(istrap[x] == -1) return false;
    if(bit&(1<<istrap[x])) return true;
    else return false;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    int N =  n;
    int M = traps.size();
    for(int i=1; i<=N; i++){
        E[i].clear();
        rE[i].clear();
        istrap[i] = -1;
        for(int j=0; j<(1<<M);j++){
            visited[i][j] = false;
        }
    }
    
    for(vector<int>& e: roads){
        E[e[0]].push_back({e[1],e[2]});
        rE[e[1]].push_back({e[0],e[2]});
    }
    
    for(int i=0; i<traps.size();i++){
        istrap[traps[i]] = i;
    }
    
    
    priority_queue<vector<int>,vector<vector<int>>, cmp> q;
    q.push({start,0,0});
    
    while(!q.empty()){
        int x = q.top()[0];
        int bit = q.top()[1];
        int d = q.top()[2];
        q.pop();
        if(visited[x][bit]) continue;
        visited[x][bit] = true;
        if(x==end) return d;
        for(auto[nx,w]: E[x]){
            if(isrv(x,bit) != isrv(nx,bit)) continue;
            if(istrap[nx] != -1) q.push({nx, bit^(1<<istrap[nx]),d+w});
            else q.push({nx,bit,d+w});
        }
        for(auto [nx,w]:rE[x]){
            if(isrv(x,bit) == isrv(nx,bit)) continue;
            if(istrap[nx] != -1) q.push({nx, bit^(1<<istrap[nx]),d+w});
            else q.push({nx,bit,d+w});
        }
    }
    
    
    
    return answer;
}