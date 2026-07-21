#include<bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    int N = numbers.size();
    vector<string> arr(N);
    for(int i =0; i<N;i++){
        arr[i] = to_string(numbers[i]);
    }
    
    sort(arr.begin(),arr.end(),cmp);
    
    for(string& s: arr) answer+=s;
    
    if(answer.front()=='0') return "0";
    
    return answer;
}