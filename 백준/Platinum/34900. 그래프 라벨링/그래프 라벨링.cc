#include<bits/stdc++.h>
using namespace std;

int arr[200001];
int parent[200001];
int findp(int x){
    if(parent[x]==x) return x;
    return parent[x] = findp(parent[x]);
}
void solve(int tc){

    int N,M;
    cin>>N>>M;
    int cnt =0;
    for(int i=1; i<=N;i++) {
        cin>>arr[i];
        cnt+=arr[i];
        parent[i]=i;
    }
    
    bool flag = (cnt == M);
    
    while(M--){
        int u,v;
        cin>>u>>v;
        flag &= (findp(u)!=findp(v));
        parent[findp(u)]= findp(v);
    }
    
    if(!flag){
        cout<<"No";
        return;
    }
    
    vector<int> sz(N+1,0);
    for(int i=1; i<=N;i++) sz[findp(i)]+=1;
    vector<int> v;
    for(int i=1; i<=N;i++) {
        if(sz[i]!=0) v.push_back(sz[i]);
    }
    sort(v.rbegin(),v.rend());
    
    int s = 0;
    
    int idx = N;
    for(int k : v){
        k-=1;
        while(idx!=0 && !arr[idx]){
            s+=1;
            idx-=1;
        }
        if(!s){
            cout<<"No";
            return;
        }
        s-=1;
        while(k--){
            while(idx!=0 && !arr[idx]){
                s+=1;
                idx-=1;
            }
            idx-=1;
        }
    }
    
    cout<<"Yes";
    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}