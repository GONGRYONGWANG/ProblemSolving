#include<bits/stdc++.h>
using namespace std;

using pii  = pair<int,int>;

struct cmp{
    bool operator()(vector<int>&a, vector<int>& b){
        if(a[1]!=b[1]) return a[1]>b[1];
        if(a[0]!=b[0]) return a[0]>b[0];
        return a[2]>b[2];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    vector<vector<int>> arr;
    for(int i=0; i<jobs.size();i++){
        int s= jobs[i][0]; int l = jobs[i][1];
        arr.push_back({s,l,i});
    }
    
    sort(arr.rbegin(),arr.rend());
    
    int t = 0;
    
    priority_queue<vector<int>,vector<vector<int>>, cmp> q;
    while(!q.empty() || !arr.empty()){
        while(!arr.empty() && arr.back()[0]<=t){
            q.push(arr.back());
            arr.pop_back();
        }
        if(q.empty()){
            t = arr.back()[0];
            continue;
        }
        answer += t + q.top()[1] - q.top()[0];
        t += q.top()[1];
        q.pop();
    }
    
    return answer/jobs.size();
}