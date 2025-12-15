#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define pq priority_queue

struct cmp{
  
  bool operator()(vector<ll>& a , vector<ll>& b){ // idx C sz
      return a[1]*b[2] < a[2]*b[1];
  }  
    
};

int nx[1001];
int prv[1001];
int parent[1001];
int findp(int x){
    if(parent[x]==x) return x;
    return parent[x] = findp(parent[x]);
}

int leaf[1001];
int sz[1001];
ll C[1001];
ll init[1001];

bool visited[1001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N,R;
	cin>>N>>R;
	
	for(int i=1; i<=N;i++){
	    cin>>C[i];
	    init[i] = C[i];
	    parent[i] = i;
	    leaf[i]=i;
	    sz[i] = 1;
	}
	
	for(int i=0; i<N-1;i++){
	    int u,v;
	    cin>>u>>v;
	    prv[v] = u;
	}
	
	pq<vector<ll>, vector<vector<ll>>, cmp> q;
    for(int i=1;i<=N;i++){
        q.push({i,C[i],1});
    }
    
    visited[R] = true;
    while(!q.empty()){
        int x= q.top()[0];
        q.pop();
        if(visited[x]) continue;
        visited[x] = true;
        int p = findp(prv[x]);
        nx[leaf[p]] = x;
        leaf[p] = leaf[x];
        parent[x] = p;
        C[p] += C[x];
        sz[p] += sz[x];
        q.push({p,C[p],sz[p]});
    }
    
    ll ret=0;
    int idx= 1;
    while(R!=0){
        ret += init[R] * idx;
        idx+=1;
        R = nx[R];
    }
    
    cout<<ret;
    
    
    return 0;
    
}
