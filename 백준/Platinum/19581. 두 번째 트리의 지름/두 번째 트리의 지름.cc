#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii> E[100001];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    for(int i=0; i<N-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }
    
    int s;
    {
        vector<int> visited(N+1,0);
        queue<int> q;
        q.push(1);
        visited[1]=1;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            for(auto&[nx,w]:E[x]){
                if(visited[nx]) continue;
                visited[nx] = visited[x]+w;
                q.push(nx);
            }
        }
        
        s= 1;
        for(int i=1; i<=N;i++){
            if(visited[i]>visited[s]) s = i;
        }
    }
    
    int ret = 0;
    {
        vector<int> visited(N+1,0);
        queue<int> q;
        q.push(s);
        visited[s] = 1;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            for(auto&[nx,w]:E[x]){
                if(visited[nx]) continue;
                visited[nx] = visited[x]+w;
                q.push(nx);
            }
        }
        
        int mx = 0;
        for(int i=1; i<=N;i++){
            mx = max(mx, visited[i]);
        }
        
        int cnt =0;
        for(int i=1; i<=N;i++){
            cnt += (visited[i]==mx);
            if(visited[i]!=mx) ret = max(ret, visited[i]-1);
        }
        
        if(cnt>=2){
            cout<<mx-1;
            return 0;
        }
        
    }
    
    int t;
    {
        vector<int> visited(N+1,0);
        queue<int> q;
        q.push(1);
        visited[1]=1;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            for(auto&[nx,w]:E[x]){
                if(nx == s) continue;
                if(visited[nx]) continue;
                visited[nx] = visited[x]+w;
                q.push(nx);
            }
        }
        
        t = 1;
        for(int i=1; i<=N;i++){
            if(visited[i]>visited[t]) t = i;
        }
    }
    
    {
        vector<int> visited(N+1,0);
        queue<int> q;
        q.push(t);
        visited[t] = 1;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            for(auto&[nx,w]:E[x]){
                if(nx==s) continue;
                if(visited[nx]) continue;
                visited[nx] = visited[x]+w;
                q.push(nx);
            }
        }
        
        int mx = 0;
        for(int i=1; i<=N;i++){
            mx = max(mx, visited[i]);
        }
        cout<<max(ret, mx - 1);
    }
    
    
    
    
    
    return 0;
}
