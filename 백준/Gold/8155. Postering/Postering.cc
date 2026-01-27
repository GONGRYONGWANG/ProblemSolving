#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	stack<int> st;
	int ret= 0;
	while(N--){
	    int d,w;
	    cin>>d>>w;
	    while(!st.empty() && st.top()>w) st.pop();
	    if(st.empty() || st.top()< w){
	        st.push(w);
	        ret += 1;
	    }
	}
	
	cout<<ret;

}
