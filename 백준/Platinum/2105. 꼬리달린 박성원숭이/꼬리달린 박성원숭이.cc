#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef pair<int,int> pii;

int E[200001][3];
bool exc[200001][3];

set<int> st[200001];
int parent[200001];
int findp(int x){
    if(parent[x]==x) return x;
    return parent[x] = findp(parent[x]);
}

int ret[200001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N;i++){
	    st[i].insert(i);
	    parent[i]=i;
	    cin>>E[i][1] >> E[i][2];
	}
	
	vector<pii> query(M);
	for(auto& [x,b] : query){
	    cin>>x>>b;
	    exc[x][b] = true;
	}
	
	
	for(int i=1; i<=N;i++){
	    for(int j=1; j<=2; j++){
	        if(E[i][j]==-1 || exc[i][j] || findp(i) == findp(E[i][j])) continue;
	        int u = findp(i); int v = findp(E[i][j]);
	        if(u>v) swap(u,v);
	        if(u==1){
	            for(int x: st[v]) {
	                ret[x] = -1;
	            }
	        }
	        if(st[u].size()<st[v].size()) swap(st[u],st[v]);
	        for(int x :st[v]){
	            st[u].insert(x);
	        }
	        parent[v] = u;
	    }
	}
	
	for(int i=M-1; i>=0; i--){
	    auto [x,b] = query[i];
	    if(E[x][b]==-1) continue;
	    int u = findp(x);
	    int v= findp(E[x][b]);
	    if(u==v) continue;
	    if(u>v) swap(u,v);
	    if(u==1){
	       for(int x: st[v]) {
	            ret[x] = i;
	       }
	    }
	    if(st[u].size()<st[v].size()) swap(st[u],st[v]);
	    for(int x :st[v]){
	        st[u].insert(x);
	    }
	    parent[v] = u;
	}
	
	ret[1] = -1;
	for(int i=1; i<=N;i++) cout<<ret[i]<<endl;
	
	
    return 0;
}
