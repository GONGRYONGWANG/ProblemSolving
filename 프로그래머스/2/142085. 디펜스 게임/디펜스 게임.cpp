#include<bits/stdc++.h>
using namespace std;

#define pq priority_queue
using ll = long long;


int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    int N = n; int K = k;
    
    pq<ll,vector<ll>,greater<ll>> q; 
    
    ll total =0;
    for(int i =0;i<enemy.size();i++){
        q.push(enemy[i]);
        if(q.size()>K){
            total += q.top();
            q.pop();
        }
        if(total > N) return i;
    }
    
    return enemy.size();
    
    return answer;
}