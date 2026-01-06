#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
 
 
int arr[15];
map<pii,tuple<int,int,int>> m;
 
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    char x;
    cin>>x;
    int state = x-'A';
    int idx = 0;
    
    int N,L;
    cin>>N>>L;
    
    for(int i=0; i<N;i++){
        char a,d;
        int b,c,e;
        cin>>a>>b>>c>>d>>e;
        m[{a-'A',b}] = {c,d-'A',e};
    }
    
    for(int i=0; i<L;i++){
        cin>>x;
        arr[i] = x-'0';
    }
    
    for(int i=0; i<(1<<L)*L*N+10;i++){
        if(idx<0 || idx>=L){
            cout<<"STOP";
            return 0;
        }
        if(!m.count({state, arr[idx]})){
            cout<<"STOP";
            return 0;
        }
        auto [c,d,e] = m[{state, arr[idx]}];
        state = d;
        arr[idx] = c;
        idx+=e;
    }
    
    cout<<"CONTINUE";
    
 
}
