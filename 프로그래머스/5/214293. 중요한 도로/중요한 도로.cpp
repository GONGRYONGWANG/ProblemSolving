#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

vector<pll> E[250001];
ll L[250001];
ll T[250001];

struct cmp{
  bool operator()(pll& a, pll& b){
      return a.second>b.second;
  }  
};

ll dist1[250001];
ll distN[250001];


vector<int> nE[250001];
bool isap[250001];
int timer = 0;
int order[250001];
int low[250001];

void dfs(int x, int p){
    order[x] = low[x] = ++timer;
    int child =  0;
    for(int nx: nE[x]){
        if(!order[nx]){
            child+=1;
            dfs(nx,x);
            low[x] = min(low[x], low[nx]);
            if(x!=1 && low[nx]>=order[x]){
                isap[x] =true;
            }
        }
        else if(nx!=p){
            low[x] = min(low[x],order[nx]);
        }
    }
    if(x==1 && child>1) isap[x] = true;
}

vector<int> solution(int n, vector<vector<int>> roads) {
    vector<int> answer;
    
    int N = n;
    int M = roads.size();
    
    for(int i=1; i<=N+M;i++){
        E[i].clear();
        L[i] = 0; T[i] = 0;
        dist1[i] = distN[i] = 0;
        isap[i] = false;
        order[i] = 0; low[i] = 0;
        nE[i].clear();
    }
    timer = 0;
    
    for(int i=0; i<M;i++){
        ll u = roads[i][0]; ll v = roads[i][1];
        ll l = roads[i][2]; ll t = roads[i][3];
        int x = N+1+i;
        L[x] = l; T[x] = t;
        
        E[u].push_back({x,l+t}); E[x].push_back({u,l+t});
        E[x].push_back({v,l+t}); E[v].push_back({x,l+t});
    }
    
    priority_queue<pll,vector<pll>, cmp> q;
    q.push({1,1});
    while(!q.empty()){
        auto [x,d] = q.top();
        q.pop();
        if(dist1[x]) continue;
        dist1[x] = d;
        for(auto&[nx,w]:E[x]){
            if(dist1[nx]) continue;
            q.push({nx,d+w});
        }
    }
    
    q.push({N,1});
    while(!q.empty()){
        auto [x,d] = q.top();
        q.pop();
        if(distN[x]) continue;
        distN[x] = d;
        for(auto&[nx,w]:E[x]){
            if(distN[nx]) continue;
            q.push({nx,d+w});
        }
    }
    
    ll totald = dist1[N] + 1;
    
    for(int i=1; i<=N+M;i++){
        for(auto& [nx,w]:E[i]){
            if(dist1[i] + w + distN[nx] != totald) continue;
            nE[i].push_back(nx);
            nE[nx].push_back(i);
        }
    }
    
    dfs(1, 0);
    
    for(int i=N+1; i<=N+M;i++){
        if(dist1[i]+distN[i]==totald){
            if(T[i] !=0 || isap[i] ){
                answer.push_back(i-N);
            }
        }
        else if(dist1[i]+distN[i]-T[i]*2 < totald){
            answer.push_back(i-N);
        }
    }
    
    sort(answer.begin(),answer.end());
    
    if(answer.empty()) answer = {-1};
    return answer;
}