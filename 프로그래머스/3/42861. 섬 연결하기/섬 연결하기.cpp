#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a.back()<b.back();
}


int findp(int x, vector<int>& parent){
    if(x==parent[x]) return x;
    return parent[x] = findp(parent[x], parent);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parent(100);
    for(int i=0;i<n;i++) parent[i]=i;
    
    sort(costs.begin(),costs.end(),cmp);
    
    
    for(auto b : costs){
        int u = b[0]; int v= b[1];
        int c = b[2];
        u = findp(u,parent); v= findp(v,parent);
        if(u==v) continue;
        answer += c;
        parent[u] = v;
    }
    
    
    return answer;
}