#include<bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int,int> m;
    for(int x: tangerine){
        m[x]+=1;
    }
    
    vector<int> v;
    for(auto it= m.begin();it!=m.end();it++){
        v.push_back(it->second);
    }
    
    sort(v.begin(),v.end());
    
    while(k>0){
        k-=v.back();
        answer+=1;
        v.pop_back();
    }
    
    return answer;
}