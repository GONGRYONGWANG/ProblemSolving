#include<bits/stdc++.h>
using namespace std;

int toint(char x){
    if(x=='(') return 1;
    else if(x==')') return -1;
    else if(x=='[') return 2;
    else if(x==']') return -2;
    else if(x=='{') return 3;
    else return -3;
}

int solution(string s) {
    int answer = 0;
    
    map<char,int> m;
    for(char x: s){
        m[x]+=1;
    }
    
    if(m['(']!=m[')']) return 0;
    if(m['{']!=m['}']) return 0;
    if(m['[']!=m[']']) return 0;
    
    
    int N = s.length();
    s += s;
    
    vector<int> DP(2*N,-1);
    for(int i=2*N-3; i>=0; i--){
        char x = s[i];
        if(toint(x)<0) continue;
        if(toint(x)+toint(s[i+1]) == 0) {
            DP[i] = i+1;
            if(DP[DP[i]+1]!=-1) DP[i] = DP[DP[i]+1];
            continue;
        }
        if(DP[i+1]!=-1 && toint(x)+toint(s[DP[i+1]+1]) == 0){
            DP[i] = DP[i+1]+1;
            if(DP[DP[i]+1]!=-1) DP[i] = DP[DP[i]+1];
            continue;
        }
    }
    
    for(int i=0; i<N;i++){
        if(DP[i] - i + 1 >= N) answer +=1;
    }
    
    return answer;
}