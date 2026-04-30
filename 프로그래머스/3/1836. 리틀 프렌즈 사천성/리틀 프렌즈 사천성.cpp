#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    
    int N = m;
    int M = n;
    vector<pair<pii,pii>> arr(26);
    for(int i=0; i<26;i++){
        arr[i] = {{-1,-1},{-1,-1}};
    }
    
    int cnt= 0;
    for(int i=0; i<N;i++){
        for(int j=0;j<M;j++){
            char x = board[i][j];
            if(x=='.' || x=='*') continue;
            cnt+=1;
            if(arr[x-'A'].first.first ==-1) arr[x-'A'].first = {i,j};
            else arr[x-'A'].second = {i,j};
        }
    }
    cnt/=2;
    
    vector<bool> visited(26,false);
    
    for(int i=0; i<26;i++){
        if(arr[i].first.first == -1) visited[i] = true;
    }
    
    bool b=true;
    while(b){
        b= false;
        for(int i=0; i<26; i++){
            if(visited[i]) continue;
            auto [p1,p2] = arr[i];
            {
                bool flag =true;
                auto[x,y] = p1;
                while(x!=p2.first || y!=p2.second){
                    if(x<p2.first) x+=1;
                    else if(x>p2.first) x-=1;
                    else if(y<p2.second) y+=1;
                    else if(y>p2.second) y-=1;
                    if(board[x][y]!='.' && board[x][y]!=char('A'+i)){
                        flag=false;
                    }
                }
                if(flag){
                    visited[i] =true;
                    b = true;
                    answer += char('A'+i);
                    board[p1.first][p1.second] = board[p2.first][p2.second] = '.';
                    break;
                }
            }
            {
                bool flag =true;
                auto[x,y] = p1;
                while(x!=p2.first || y!=p2.second){
                    if(y<p2.second) y+=1;
                    else if(y>p2.second) y-=1;
                    else if(x<p2.first) x+=1;
                    else if(x>p2.first) x-=1;
                    if(board[x][y]!='.' && board[x][y]!=char('A'+i)){
                        flag=false;
                    }
                }
                if(flag){
                    visited[i] =true;
                    b = true;
                    answer += char('A'+i);
                    board[p1.first][p1.second] = board[p2.first][p2.second] = '.';
                    break;
                }
            }
        }
    }
    
    if(answer.size() != cnt) answer = "IMPOSSIBLE";
    
    return answer;
}