#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

ll L[16][16];
ll R[16][16];
int cnt[16];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
    string s;
    cin>>s;
    
    for(char x: s){
        int d = x-'a';
        cnt[d]+=1;
        for(int i=0;i<16;i++){
            if(d==i) continue;
            L[d][i] += cnt[i];
            R[i][d] += cnt[i];
        }
    }
    
    ll ans = 0;
    for(int bit= 0;bit<(1<<16);bit++){
        ll ret =0;
        for(int i=0; i<16;i++){
            if(bit&(1<<i)){ // up
                for(int j=0; j<i;j++){
                    if(bit&(1<<j)) continue;
                    ret += R[i][j];
                }
            }
            else{ // right
                for(int j=0; j<i; j++){
                    if(!(bit&(1<<j))) continue;
                    ret += L[i][j];
                }
            }
        }
        ans= max(ans,ret);
    }
    
	cout<<ans;
	
	
	
	
	
	
	
	return 0;
}
