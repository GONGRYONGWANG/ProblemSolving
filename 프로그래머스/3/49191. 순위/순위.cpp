#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    int N = n;
    vector<vector<int>> adj(N+1,vector<int>(N+1,0));
    
    for(vector<int>& v: results){
        adj[v[0]][v[1]] =true;
    }
    
    for(int i=1; i<=N;i++) adj[i][i] = true;
    
    for(int k=1; k<=N;k++){
        for(int i=1; i<=N;i++){
            for(int j=1; j<=N;j++){
                adj[i][j] |= (adj[i][k] & adj[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N;i++){
        int cnt =0 ;
        for(int j=1; j<=N;j++){
            cnt += adj[i][j] | adj[j][i];
        }
        answer += (cnt==N);
    }
    
    
    return answer;
}