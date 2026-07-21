#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int N = prices.size();
    answer.resize(N,0);
    
    stack<int> st;
    for(int i=0; i<N;i++){
        answer[i] = N-i-1;
        while(!st.empty() && prices[st.top()] > prices[i]){
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    
    return answer;
}