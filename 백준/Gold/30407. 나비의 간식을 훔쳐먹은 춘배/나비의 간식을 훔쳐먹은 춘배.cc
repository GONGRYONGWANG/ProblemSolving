#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int DP[19][101][3];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N,H,D,K;
	cin>>N>>H>>D>>K;
	
	DP[0][D][0] = H;
	
	for(int i=1; i<=N;i++){
	    int R;
	    cin>>R;
	    
	    for(int j=0; j<=70;j++){
	        if(DP[i-1][j][0] > max(0, R - j - K)) {
	            DP[i][j+K][0] = max(DP[i][j+K][0] ,DP[i-1][j][0]- max(0, R - j - K) );
	        }
	        if(DP[i-1][j][0] > max(0, R - j)){
	            DP[i][j][1] = max(DP[i][j][1] , DP[i-1][j][0]- max(0, R - j) );
	        }
	        
	        if(DP[i-1][j][0] > max(0, R - j)/2) DP[i][j][0] = max(DP[i][j][0] ,DP[i-1][j][0]- max(0, R - j)/2 );
	        
	        DP[i][j+K][2] = max(DP[i][j+K][2], DP[i-1][j][1]);
	        
	        if(DP[i-1][j][2] > max(0, R - j - K)) {
	            DP[i][j+K][2] = max(DP[i][j+K][2] ,DP[i-1][j][2]- max(0, R - j - K) );
	        }
	        
	        if(DP[i-1][j][2] > max(0, R - j)/2) DP[i][j][2] = max(DP[i][j][2] ,DP[i-1][j][2]- max(0, R - j)/2 );
	        
	    }
	    
	}
	
	int ret= 0;
	for(int j=0; j<=100;j++){
	    ret = max(ret, DP[N][j][0]);
	    ret = max(ret,DP[N][j][1]);
	    ret = max(ret, DP[N][j][2]);
	}
	
	if(ret==0) cout<<-1;
	else cout<<ret;
	
	
}
