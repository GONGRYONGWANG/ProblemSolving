#include <bits/stdc++.h>
using namespace std;
#define endl "\n"



void solve(){
    
    
    int tc = 1;
    while(1){
        int r,w, l;
        cin>>r;
    
        if(r==0) break;
        cin>>w>>l;
        
        cout<<"Pizza "<<tc<<( (4*r*r >= w*w+l*l) ? " fits on the table."
        : " does not fit on the table." ) <<endl;
        
        tc++;
    }
    
        
    
    
    
    
    
    
    
    
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int T;
    T = 1;
    while(T--) solve();
    
    
    
    
    
    
    return 0;

}
