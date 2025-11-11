#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
ll mod = 1e9 + 9;

int psum[100001];

ll tree[400004];
void update(int node, int start, int end, int x, ll v){
    if(x>end||x<start) return;
    if(start==end){
        tree[node] = (tree[node]+v)%mod;
        return;
    }
    int mid=(start+end)/2;
    update(node*2,start,mid,x,v);
    update(node*2+1,mid+1,end,x,v);
    tree[node] = (tree[node*2]+tree[node*2+1])%mod;
}

ll get(int node, int start, int end, int left , int right){
    if(left>end||right<start) return 0;
    if(left<=start&&right>=end) return tree[node];
    int mid= (start+end)/2;
    return (get(node*2,start,mid,left,right) + get(node*2+1,mid+1,end,left,right))%mod;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	map<int,int> m;
	m[0]=0;
    for(int i=1; i<=N;i++){
        cin>>psum[i];
        psum[i] += psum[i-1];
        m[psum[i]] = 0;
    }
	
	m.begin()->second = 1;
	for(auto it = next(m.begin());it!=m.end();it++){
	    it->second = prev(it)->second + 1;
	}
	
	for(int i=1; i<=N;i++) psum[i] = m[psum[i]];
	
	update(1,1,N+1,m[0],1);
	
	for(int i=1; i<=N;i++){
	    int x = psum[i];
	    ll g = get(1,1,N+1,1,x);
	    if(i==N){
	        cout<<g<<endl;
	        return 0;
	    }
	    update(1,1,N+1,x,g);
	}
	
	return 0;
	
	
}
