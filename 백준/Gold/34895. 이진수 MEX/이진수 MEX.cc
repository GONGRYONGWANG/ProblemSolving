#include <bits/stdc++.h>
using namespace std;

bool visited[1000000];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N; cin>>N;
	string s; cin>>s;
	for(int i=0; i<N; i++){
	    int total = 0;
	    for(int j=i; j<min(i+18,N);j++){
	        total <<= 1;
	        total += s[j]-'0';
	        visited[total] = true;
	    }
	}
	
	for(int i=1; i<1000000;i++){
	    if(!visited[i]){
	        stack<int> st;
	        while(i){
	            st.push(i%2);
	            i/=2;
	        }
	        while(!st.empty()){
	            cout<<st.top();
	            st.pop();
	        }
	        return 0;
	    }
	}
	
	
	return 0;
}
