#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end());
    
    int N = phone_book.size();
    for(int i=1; i<N;i++){
        string a = phone_book[i-1];
        string b = phone_book[i];
        if(a.length()>=b.length()) continue;
        answer &= !(a==b.substr(0,a.length()));
    }
    
    
    
    
    return answer;
}