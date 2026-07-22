#include<bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    int N = dungeons.size();
    
    vector<int> cost((1<<N),0);
    
    vector<bool> dp((1<<N),false);
    dp[0] = true;
    
    for(int bit = 1; bit<(1<<N); bit++){
        int cnt = 0;
        for(int i=0; i<N;i++){
            if(!(bit&(1<<i))) continue;
            cnt+=1;
            cost[bit] += dungeons[i][1]; 
            if(!dp[bit-(1<<i)]) continue;
            if(k - cost[bit-(1<<i)] >= dungeons[i][0]) dp[bit] = true;
        }
        if(dp[bit]) answer = max(answer, cnt);
    }
    
    
    
    
    return answer;
}