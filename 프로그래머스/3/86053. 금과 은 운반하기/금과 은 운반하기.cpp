#include<bits/stdc++.h>
using namespace std;
using ll = long long;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    int N = g.size();
    
    ll l = 0;
    ll r = 1e15;
    
    int cnt = 0;
    
    while(l<r){
        cnt+=1;
        ll m = (l+r)/2;
        ll x,y,z;
        
        x = y = z = 0;
        
        for(int i=0; i<N;i++){
            if(t[i]>m) continue;
            ll d = 1 + (m-t[i])/(t[i]*2);
            ll W = d*w[i];
            if(g[i]+s[i]<=W){
                x += g[i]; y += s[i];
                continue;
            }
            ll dx = max(0ll, W-s[i]);
            ll dy = max(0ll, W-g[i]);
            ll dz = W - dx - dy;
            x += dx; y += dy; z += dz;
        }
        
        x = min(x,ll(a)); y = min(y, ll(b));
        
        if(x+y+z<a+b) l = m+1;
        else r = m;
        
    }
            
    
    answer =  l;
    
    return answer;
}