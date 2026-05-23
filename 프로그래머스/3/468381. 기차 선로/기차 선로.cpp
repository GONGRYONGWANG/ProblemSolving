#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N,M;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


int backtrack(int x, int y, int dir, int cnt, vector<vector<int>>& board){
    if(x+y == N+M-1) return (cnt== 0);
    if(x<0 || x>=N || y<0 || y>=M) return 0;
    if(board[x][y]==-1) return 0;
    
    if(board[x][y] ==0){
        int ret= 0;
        for(int i=1; i<=7; i++){
            board[x][y] = i;
            ret += backtrack(x,y,dir,cnt + 1 + (i==3),board);
        }
        board[x][y] = 0;
        return ret;
    }
    
    cnt -= 1;
    
    if(board[x][y]==1){
        if(dir!=0 && dir!=2) return 0;
        return backtrack(x+dx[dir],y+dy[dir],dir, cnt,board);
    }
    else if(board[x][y] == 2){
        if(dir!=1 && dir!= 3) return 0;
        return backtrack(x+dx[dir],y+dy[dir],dir,cnt,board);
    }
    else if(board[x][y]== 3){
        return backtrack(x+dx[dir],y+dy[dir],dir,cnt,board);
    }
    else if(board[x][y] == 4){
        if(dir!=0 && dir!= 1) return 0;
        if(dir==0) return backtrack(x+dx[3],y+dy[3],3,cnt,board);
        else return backtrack(x+dx[2],y+dy[2],2,cnt,board);
    }
    else if(board[x][y] == 5){
        if(dir!=1 && dir!= 2) return 0;
        if(dir==1) return backtrack(x+dx[0],y+dy[0],0,cnt,board);
        else return backtrack(x+dx[3],y+dy[3],3,cnt,board);
    }
    else if(board[x][y] == 6){
        if(dir!=2 && dir!= 3) return 0;
        if(dir==2) return backtrack(x+dx[1],y+dy[1],1,cnt,board);
        else return backtrack(x+dx[0],y+dy[0],0,cnt,board);
    }
    else if(board[x][y] == 7){
        if(dir!=0 && dir!= 3) return 0;
        if(dir==0) return backtrack(x+dx[1],y+dy[1],1,cnt,board);
        else return backtrack(x+dx[2],y+dy[2],2,cnt,board);
    }
}

int solution(vector<vector<int>> grid) {
    int answer = 0;
    
    N = grid.size();
    M = grid.front().size();
    
    int cnt = 0;
    for(int i=0; i<N;i++){
        for(int j=0;j<M;j++){
            cnt += (grid[i][j] > 0 ) + (grid[i][j]==3);
        }
    }
    
    answer = backtrack(0,0,0, cnt, grid);
    
    
    
    return answer;
}