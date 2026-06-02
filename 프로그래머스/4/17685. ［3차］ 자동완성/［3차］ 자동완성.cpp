#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
ull p = 998244353;
ull q = 1e9+7;

int solution(vector<string> words) {
    int answer = 0;
    
    map<tuple<int,ull,ull>, int> m;
    
    for(string& s: words){
        ull h1 = 0; ull h2 = 0;
        int len = 0;
        for(char& c : s){
            h1 = h1 * p + (c-'a');
            h2 = h2 * q + (c-'a');
            len += 1;
            m[{len, h1, h2}] +=1;
        }
    }
    
    for(string& s: words){
        ull h1 = 0; ull h2 = 0;
        int len = 0;
        for(char& c : s){
            h1 = h1 * p + (c-'a');
            h2 = h2 * q + (c-'a');
            len += 1;
            if(m[{len,h1,h2}]==1) break;
        }
        answer += len;
    }
    
    return answer;
}