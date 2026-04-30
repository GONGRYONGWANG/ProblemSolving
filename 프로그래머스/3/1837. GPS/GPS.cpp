#include <vector>

using namespace std;

const int inf = 1e9+7;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    int N = n;
    int M = m;
    vector<vector<bool>> adj(N+1,vector<bool>(N+1,false));
    for(int i=0; i<M;i++){
        int u = edge_list[i][0];
        int v= edge_list[i][1];
        adj[v][u] = adj[u][v] = true;
    }
    
    for(int i=1; i<=N;i++) adj[i][i] =true;
    
    vector<int> DP(N+1,inf);
    DP[gps_log.front()] = 0;
    for(int i=1; i<k-1; i++){
        vector<int> nx(N+1,inf);
        for(int s = 1; s<=N;s++){
            for(int e =1; e<=N;e++){
                if(!adj[s][e]) continue;
                nx[e] = min(nx[e], DP[s] + 1 - (e==gps_log[i]));
            }   
        }
        swap(DP,nx);
    }
    
    int ans = inf;
    for(int i=1; i<=N;i++){
        if(!adj[i][gps_log.back()]) continue;
        ans = min(ans, DP[i]);
    }
    
    if(ans==inf) answer = -1;
    else answer = ans;
    return answer;
}