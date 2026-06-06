#include<bits/stdc++.h>

using namespace std;

int DP[1000][1000];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int N = board.size();
    int M = board.front().size();
    
    for(int i=0;i<N;i++){
        for(int j=0; j<M;j++){
            DP[i][j] = 0;
        }
    }
    
    for(vector<int>& v : skill){
        int r1 = v[1]; int c1 = v[2];
        int r2  = v[3]; int c2 = v[4];
        int d = v[5];
        if(v[0]==1) d= -d;
        DP[r2][c2] += d;
        if(r1!=0) DP[r1-1][c2]-=d;
        if(c1 != 0 ) DP[r2][c1-1] -=d;
        if(r1!=0 && c1!=0){
            DP[r1-1][c1-1] +=d;
        }
        
    }
    
    for(int i=0; i<N;i++){
        for(int j=M-1; j>=1; j--){
            DP[i][j-1] += DP[i][j];
        }
    }
    
    for(int j=0;j<M;j++){
        for(int i=N-1; i>=1;i--){
            DP[i-1][j] += DP[i][j];
        }
    }
    
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            answer += (DP[i][j] + board[i][j] > 0);
        }
    }
    
    
    
    return answer;
}