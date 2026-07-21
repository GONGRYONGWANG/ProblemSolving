#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>, greater<int>> q;
    for(int x: scoville) q.push(x);
    
    while(q.size()>=2 && q.top()<K){
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        q.push(x+2*y);
        answer+=1;
    }
    
    if(q.top()<K) answer = -1;
    
    
    return answer;
}