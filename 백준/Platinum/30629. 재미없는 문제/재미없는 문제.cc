#include <bits/stdc++.h>
using namespace std;



int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N,M;
	cin>>N>>M;
	
	
	int x = 1;
	while(x+M/x > N) x++;
	
	for(int i=0; i<x-1; i++) {
	    cout<<1<<" ";
	    N -= 1;
	}
	for(int i=1; i*x + x-1 <= M; i++) {
	    cout<<x<<" ";
	    N -= 1;
	}
	if((M-x+1)%x) {
	    cout<< (M-x+1)%x<<" ";
	    N -= 1;
	}
	
	while(N--) cout<<0<<" ";
	
	
    return 0;
}
