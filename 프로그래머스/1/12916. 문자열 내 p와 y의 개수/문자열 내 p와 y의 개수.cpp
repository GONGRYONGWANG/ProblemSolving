#include <string>
#include <iostream>
#include<map>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    map<char,int> m;
    for(char c: s){
        m[c]+=1;
    }
    
    answer = (m['p']+m['P'] == m['y']+m['Y']);
    

    
    
    return answer;
}