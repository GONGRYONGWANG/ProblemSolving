#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    ll x,y;
    cin>>x>>y;
    
    ll a = -x,b = -y;
    int dir = 0;
    pll ret= {a,b};
    
    char t; ll p;
    while(cin>>t){
        cin>>p;
        if(t=='T'){
            dir = (dir+p)%4;
            continue;
        }
        if(a*(a+dx[dir]*p)<0 && b*b<ret.first*ret.first+ret.second*ret.second){
            ret = {0,b};
        }
        if(b*(b+dy[dir]*p) <0 && a*a<ret.first*ret.first+ret.second*ret.second){
            ret = {a,0};
        }
        a += dx[dir]*p;
        b += dy[dir]*p;
        if(a*a+b*b<ret.first*ret.first+ret.second*ret.second){
            ret = {a,b};
        }
    }
    
    if(ret.first==0 && ret.second == 0) cout<<-1;
    else cout<<ret.first+x<<" "<<ret.second+y;
 
    return 0;
}
