#include<bits/stdc++.h>
using namespace std;

#define endl "\n"


void solve(int tc){
    
    int N,M;
    cin>>N>>M;
    
    int cnt= 0 ;
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            char x; cin>>x;
            cnt += (x=='.');
        }
    }
    
    if(cnt%2) cout<<"sewon";
    else cout<<"pizza";
    cout<<endl;
    
    return;
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int T;
    cin>>T;
    for(int tc= 1; tc<=T;tc++){
        solve(tc);
    }
    
    
    
    
    
    return 0;
    
}