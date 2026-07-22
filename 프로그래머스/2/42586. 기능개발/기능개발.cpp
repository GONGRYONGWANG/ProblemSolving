#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int N = progresses.size();
    vector<int> v(N);
    
    for(int i=0; i<N;i++){
        v[i] = (100-progresses[i]+speeds[i]-1)/speeds[i];
    }
    
    int s = v.front();
    
    int cnt = 0;
    for(int x : v){
        if(x<=s) cnt+=1;
        else{
            answer.push_back(cnt);
            s = x;
            cnt = 1;
        }
    }
    
    answer.push_back(cnt);
    
    return answer;
}