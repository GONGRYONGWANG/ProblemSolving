#include <bits/stdc++.h>
using namespace std;

int findp(int x, vector<int>& parent){
    if(parent[x]==x) return x;
    return parent[x] = findp(parent[x], parent);
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer = {0,0};
    
    vector<int> cnt(1000001,0);
    vector<int> parent(1000001);
    for(int x : nodes){
        parent[x] = x;
    }
    
    for(int i=0; i<edges.size();i++){
        int u = edges[i][0]; int v = edges[i][1];
        cnt[u]+=1; cnt[v]+=1;
        parent[findp(u, parent)] = findp(v, parent);
    }
    
    vector<int> A(1000001,0);
    vector<int> B(1000001,0);
    
    for(int x : nodes){
        A[findp(x, parent)] +=  !((x^cnt[x])&1);
        B[findp(x, parent)] +=  (x^cnt[x])&1;
    }
    
    for(int x: nodes){
        if(findp(x,parent) !=x) continue;
        answer[0] += (A[x] == 1);
        answer[1] += (B[x] == 1);
    }
    
    return answer;
}