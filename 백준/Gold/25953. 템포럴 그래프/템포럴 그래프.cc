#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> arr[1000];

int main() {
	// your code goes here
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int N, T, M; cin>>N >>T >> M;
    int a,b;
    cin>>a>>b;
    vector<int> dist(N,1e9);
    dist[a] = 0;
    for(int t=0;t<T;t++){
        vector<int> nx = dist;
        for(int i=0; i<M;i++){
            int u,v,w;
            cin>>u>>v >> w;
            nx[u] = min(nx[u],dist[v]+w);
            nx[v] = min(nx[v] , dist[u]+w);
        }
        dist =nx;
    }
    

    if(dist[b]==1e9) cout<<-1;
    else cout<<dist[b];
    
    
    
    
    return 0;
}
