#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
 
void solve(int tc) {
   
    int N;
    cin>>N;
    int d,h,k,u;
    cin>>d>>h>>k>>u;
    
    cout<<"YES"<<endl;
 
    if(h<=N && d<=N){
        while(d--) cout<<"D";
        while(k--) cout<<"K";
        while(u--) cout<<"U";
        while(h--) cout<<"H";
    }
    else if(d>N){
        while(u--) cout<<"U";
        while(k--) cout<<"K";
        while(d--) cout<<"D";
        while(h--) cout<<"H";
    }
    else{
        while(d--) cout<<"D";
        while(k--) cout<<"K";
        while(h--) cout<<"H";
        while(u--) cout<<"U";
    }
    cout<<endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}