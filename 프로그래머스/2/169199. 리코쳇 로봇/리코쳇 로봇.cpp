#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int DP[100][100][5];

int solution(vector<string> board) {
    int answer = 0;
    int N = board.size();
    int M = board.front().size();
    
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            for(int dir =0 ; dir<5;dir++){
                DP[i][j][dir] = 0;
            }
        }
    }
    
    int a,b;
    deque<tuple<int,int,int,int>> q;
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            if(board[i][j]=='R') {
                DP[i][j][4] = 1;
                q.push_back({i,j,4,1});
            }
            else if(board[i][j]=='G'){
                a=i;b=j;
            }
        }
    }
    
    while(!q.empty()){
        auto [x,y,d, c] = q.front();
        q.pop_front();
        DP[x][y][d] = c; 
        if(d==4){
            for(int dir=0;dir<4;dir++){
                if(!DP[x][y][dir]) q.push_back({x,y,dir,c+1});
            }
            continue;
        }
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(nx<0||nx>=N||ny<0||ny>=M || board[nx][ny]=='D'){
            if(!DP[x][y][4]) q.push_front({x,y,4,c});
            continue;
        }
        if(!DP[nx][ny][d]) q.push_front({nx,ny,d,c});
    }
    
    answer = DP[a][b][4]-1;
    
    
    return answer;
}