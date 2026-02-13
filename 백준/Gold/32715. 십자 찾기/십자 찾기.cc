#include <bits/stdc++.h>
using namespace std;

int csum[2501][2501];
int rsum[2501][2501];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int N,M,K;
    cin>>N>>M>>K;
    
    for(int i=1; i<=N;i++){
        for(int j=1; j<=M;j++){
            cin>>csum[i][j];
            rsum[i][j] = csum[i][j];
            csum[i][j] += csum[i-1][j];
            rsum[i][j] += rsum[i][j-1];
        }
    }
    
    int ret= 0;
    
    for(int i=K+1; i+K<=N;i++){
        for(int j=K+1; j+K<=M;j++){
            ret += (csum[i+K][j] - csum[i-K-1][j]== 2*K+1 && 
            rsum[i][j+K] -rsum[i][j-K-1]==2*K+1);
        }
    }

    cout<<ret;

    return 0;
}
