#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 1e15+9

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

ll DP[52][52][2500];
ll board[52][52];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    
    int N= m;
    int M = n;
    
    for(int i=0; i<=N + 1;i++){
        for(int j=0; j<=M + 1;j++){
            for(int k=0; k<N*M;k++){
                DP[i][j][k] = INF;
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M;j++){
            board[i+1][j+1] = time_map[i][j];
            if(time_map[i][j] == - 1) board[i+1][j+1] = INF;
        }
    }
    
    DP[1][1][0] = 0;
    for(int k=1; k<N*M; k++){
        for(int i=1; i<=N;i++){
            for(int j=1; j<=M;j++){
                for(int dir=0;dir<4;dir++){
                    int nx = i+dx[dir]; int ny = j+dy[dir];
                    DP[i][j][k] = min(DP[i][j][k], DP[nx][ny][k-1] + board[i][j]);
                }
            }
        }
    }
    
    for(int k=1; k<N*M;k++){
        if(DP[N][M][k]<= s){
            return {k, int(DP[N][M][k])};
        }
    }
    
    return {-1,-1};
    
}