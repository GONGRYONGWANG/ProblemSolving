#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N,M;
	cin>>N>>M;
	string s;
	cin>>s;
	
	if(M==0){
	    cout<<1;
	    return 0;
	}
	
	M = min(N*25,M);
	
	ll mod = 998244353;
	vector<ll> DP(M+1,0);
	for(int i=0; i<=M;i++) {
	    DP[i]=min(i+1,26);
	    if(i!=0) DP[i] += DP[i-1];
	}
	
	
	for(int i=0; i<N-1; i++){
	    vector<ll> nx(M+1,0);
	    for(int j=0; j<=M; j++){
	        nx[j] = DP[j];
	        if(j-26>=0) nx[j] += mod - DP[j-26];
	        if(j!=0) nx[j]+=nx[j-1];
	        nx[j]%=mod;
	    }
	    DP=nx;
	}
	
	cout<<(DP[M]+mod-DP[M-1])%mod;
	
	


    return 0;
}
