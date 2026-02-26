#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll mod = 998244353;

int sz[200001];

ll dfs(int x , int p, vector<vector<pll>>& E){
    ll ret = 1;
    ll cnt = 1;
    sz[x] = 1;
    for(auto& [nx,w] : E[x]){
        if(nx==p) continue;
        ret = ret * dfs(nx,x,E) % mod;
        sz[x] += sz[nx];
        cnt += sz[nx]%2;
    }
    
    for(int i=1; i<=cnt;i+=2){
        ret = ret * i%mod;
    }
    return ret;
}

void solve(){
    int N;
    cin>>N;
    N*=2;
    
    vector<vector<pll>> E(N+1);
    for(int i=0; i<N-1; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }
    
    cout<<dfs(1,0,E)<<endl;
    
    
    
    
    
    return;
}

int main() {
	// your code goes here
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	while(T--){
	    solve();
	}
	
	
	
	

    return 0;
}
