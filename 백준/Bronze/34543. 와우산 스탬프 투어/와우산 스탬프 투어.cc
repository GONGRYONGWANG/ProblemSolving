#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, W;
    cin>>N >>W;
    int ret = N*10;
    if(N>=3) ret += 20;
    if(N==5) ret += 50;
    if(W>1000) ret-=15;
    cout<<max(ret,0);
    
    return 0;
}