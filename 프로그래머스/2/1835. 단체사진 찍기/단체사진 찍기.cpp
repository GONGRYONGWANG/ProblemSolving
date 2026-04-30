#include<bits/stdc++.h>
using namespace std;


int solution(int n, vector<string> data) {
    int answer = 0;
    
    int N = n;
    string s = "ACFJMNRT";
    map<char,int> m;
    for(int i=0; i<8;i++){
        m[s[i]] = i;
    }
    
    vector<tuple<int,int, char, int>> arr;
    for(string& D : data){
        arr.push_back({m[D[0]],m[D[2]],D[3],D[4]-'0'});
    }
    
    vector<int> P= {0,1,2,3,4,5,6,7};
    
    do{
        bool b=true;
        for(auto& [U,V,t,d] : arr){
            int u = P[U];
            int v= P[V];
            if(t=='=') b &= (abs(u-v)-1==d);
            else if(t=='<') b&=(abs(u-v)-1<d);
            else b&=(abs(u-v)-1>d);
        }
        answer+=b;
    }while(next_permutation(P.begin(),P.end()));
    
    
    
    
    return answer;
}