#include<bits/stdc++.h>
using namespace std;

int inf = 1e9;

int DP[6][16];

struct cmp{
    bool operator()(int a, int b){
        return a > b ;
    }
};

int K;

int dp(int t, int n, vector<vector<int>> &reqs){
    if(t>K) return 0;
    if(DP[t][n]!=inf) return DP[t][n];
    for(int i= 0;i<=n;i++){
        int sz = i+1;
        int ret =0;
        priority_queue<int,vector<int>, cmp> q;
        for(vector<int> v : reqs){
            if(v[2]!=t) continue;
            int s = v[0];
            int d = v[1];
            while(!q.empty() && q.top()<=s){
                q.pop();
                sz+=1;
            }
            if(sz==0){
                ret += q.top()-s;
                q.push(q.top()+d);
                q.pop();
            }
            else{
                q.push(s+d);
                sz-=1;
            }
        }
        DP[t][n]=min(DP[t][n],ret + dp(t+1,n-i,reqs));
    }
    return DP[t][n];
}

int solution(int k, int n, vector<vector<int>> reqs) {
    K=k;
    int answer = 0;
    for(int i=1; i<=k;i++){
        for(int j=0; j<=n-k;j++){
            DP[i][j]=inf;
        }
    }
    answer = dp(1,n-k, reqs);
    return answer;
}