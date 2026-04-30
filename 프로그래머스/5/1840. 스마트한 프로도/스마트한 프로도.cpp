#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

pii E[1000001];
int Alloc[100001];
int Goal[100001];

unordered_set<int> st[3];

int getcnt(int e){
    auto&[u,v] = E[e];
    return (Alloc[u]!=0) + (Alloc[v]!=0);
}

void rmv(int e){
    auto&[u,v] = E[e];
    if(Goal[u]) st[getcnt(Goal[u])].erase(Goal[u]);
    if(Goal[v]) st[getcnt(Goal[v])].erase(Goal[v]);
    Alloc[u] = Alloc[v] = 0;
    if(Goal[u]) st[getcnt(Goal[u])].insert(Goal[u]);
    if(Goal[v]) st[getcnt(Goal[v])].insert(Goal[v]);
}

vector<vector<int>> solution(int n, int m, vector<int> a, vector<int> b, int k, int m1, int m2, vector<int> e1, vector<int> e2) {
    vector<vector<int>> answer;
    
    int N = n; int M= m;
    
    for(int i=1; i<=N;i++){
        Alloc[i] = Goal[i] = 0;
    }
    
    for(int i=0; i<M;i++){
        E[i+1] = {a[i],b[i]};
    }
    
    for(int& e: e1){
        auto& [u,v] = E[e];
        Alloc[u] = Alloc[v] = e;
    }
    
    for(int& e : e2){
        auto&[u,v] = E[e];
        Goal[u] = Goal[v] = e;
        if(Alloc[u]==e) continue;
        st[getcnt(e)].insert(e);
    }
    
    while(!st[0].empty() || !st[1].empty() || !st[2].empty()){
        if(!st[0].empty()){
            int e = *st[0].begin();
            st[0].erase(e);
            answer.push_back({1,e});
            auto&[u,v] = E[e];
            Alloc[u] = Alloc[v] = e;
        }
        else if(!st[1].empty()){
            int e= *st[1].begin();
            auto&[u,v] = E[e];
            if(!Alloc[u]) swap(u,v);
            int cur = Alloc[u];
            rmv(cur);
            answer.push_back({0,cur});
        }
        else {
            int e = *st[2].begin();
            auto&[u,v] = E[e];
            int cur = Alloc[u];
            rmv(cur);
            answer.push_back({0,cur});
        }
    }
    
    for(int i=1; i<=N;i++){
        if(Alloc[i] != Goal[i]){
            int e = Alloc[i];
            answer.push_back({0,e});
            auto&[u,v] = E[e];
            Alloc[u] = Alloc[v] = 0;
        }
    }
    
    
    return answer;
}