#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	vector<int> arr;
	for(int i=1; i<=N; i++){
	    int x; cin>>x;
	    while(x--) arr.push_back(i);
	}
	
	int ans = 1e9+7;
	for(int i=0; i<N; i++){
	    int ret= 0;
	    for(int j=i; j<i+N; j++){
	        int d = (j-i+1 - arr[j%N]);
	        if(d<0) d+=N;
	        ret+= d*d;
	    }
	    ans = min(ans,ret);
	}
	cout<<ans;

    return 0;
}
