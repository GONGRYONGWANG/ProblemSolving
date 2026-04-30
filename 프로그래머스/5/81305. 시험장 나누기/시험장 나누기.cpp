#include<bits/stdc++.h>
using namespace std;

using pii  = pair<int,int>;



int arr[10000];
pii DP[10000];
vector<int> child[10000];
int parent[10000];

int thres;
void dfs(int x){
    DP[x] = {0,arr[x]};
    vector<int> v;
    for(int nx:child[x]){
        dfs(nx);
        DP[x].first += DP[nx].first;
        v.push_back(DP[nx].second);
    }
    sort(v.begin(),v.end());
    for(int val : v){
        if(DP[x].second + val > thres){
            DP[x].first+=1;
        }
        else DP[x].second += val;
    }
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;

    int N = num.size();

    for(int i=0; i<N;i++) parent[i] = -1;
    int mxnum = 0;
    for(int i=0; i<N; i++){
        arr[i] = num[i];
        mxnum = max(mxnum, arr[i]);
        child[i].clear();
        for(int c : links[i]){
            if(c!=-1) {
                child[i].push_back(c);
                parent[c] = i;
            }
        }
    }

    int root;
    for(int i=0; i<N;i++){
        if(parent[i] == -1) root = i;
    }

    int l = mxnum;
    int r = 100000000;
    while(l<r){
        int m = (l+r)/2;
        thres = m;
        dfs(root);
        if(DP[root].first+1>k) l = m+1;
        else r = m;
    }

    answer = l;


    return answer;
}