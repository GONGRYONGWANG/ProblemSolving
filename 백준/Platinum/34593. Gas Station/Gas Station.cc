#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;
#define pll pair<ll,ll>


vector<pair<ll,ll>> E[200001];


void solve(int tc){
    
    int N, K;
    cin>>N >> K;
    
    
    ll l = 0;
    ll r = 1e18;
    
    vector<int> initind(N+1,0);
    for(int i=0; i<N-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
        l = max(l,w);
        initind[u]+=1;
        initind[v]+=1;
    }
    
    while(l<r){
        ll m = (l+r)/2;
        int ret= 0 ;
        vector<int> ind = initind;
        vector<bool> visited(N+1,false);
        queue<int> q;
        for(int i=1; i<=N;i++){
            if(ind[i]==1) q.push(i);
        }
        
        vector<pll> mx(N+1, {0,0});
        
        while(!q.empty()){
            int x= q.front();
            q.pop();
            visited[x] = true;
            
            int p =0 ;
            ll to_parent = 0;
            for(auto [nx, d] : E[x]){
                if(!visited[nx]){
                    p = nx; to_parent = d;
                } 
            }
    
            if(mx[x].first+mx[x].second > m || mx[x].first + to_parent>m){
                ret += 1;
                if(p!=0){
                    if(to_parent>=mx[p].first){
                        mx[p] = {to_parent,mx[p].first};
                    }
                    else mx[p].second = max(mx[p].second , to_parent);
                }
            }
            else{
                if(p!=0){
                    if(mx[x].first + to_parent>=mx[p].first){
                        mx[p] = {mx[x].first + to_parent,mx[p].first};
                    }
                    else mx[p].second = max(mx[p].second , mx[x].first + to_parent);
                }
            }
            
            if(p!=0) {
                ind[p]-=1;
                if(ind[p]==1) q.push(p);
            }
        }
        if(ret > K) l=m+1;
        else r = m;
    }
    
    
    
    cout<<l;
    
    return;
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int T = 1;
    // cin>>T;
    for(int tc= 1; tc<=T;tc++){
        solve(tc);
    }
    
    return 0;
    
}