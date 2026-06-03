#include <string>
#include <vector>

using namespace std;

vector<int> E[100001];
int DP[100001][2];

void dfs(int x, int p){
    DP[x][0] = 0; DP[x][1] = 1;
    for(int nx:E[x]){
        if(nx==p) continue;
        dfs(nx,x);
        DP[x][0]+=DP[nx][1];
        DP[x][1] += min(DP[nx][0], DP[nx][1]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    int N = n;
    for(int i=1; i<=N;i++){
        E[i].clear();
    }
    for(int i=0; i<N-1; i++){
        int u = lighthouse[i][0]; int v = lighthouse[i][1];
        E[u].push_back(v); E[v].push_back(u);
    }
    
    dfs(1, 0);
    
    answer = min(DP[1][0],DP[1][1]);
    
    
    return answer;
}