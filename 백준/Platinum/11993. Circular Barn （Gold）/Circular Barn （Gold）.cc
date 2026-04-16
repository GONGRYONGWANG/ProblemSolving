#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[200001];
int init[200001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	for(int i=1; i<=N;i++){
	    cin>>arr[i];
	    arr[i+N] = arr[i];
	    init[i+N] = init[i] = arr[i];
	}
	for(int i=1; i<=2*N; i++){
	    arr[i] += arr[i-1]-1;
	}
	
	multiset<ll> st;
	for(int i=1; i<=N;i++) st.insert(arr[i]);
	
	int idx = 1;
	while(*st.begin() < arr[idx-1]){
	    st.erase(st.find(arr[idx]));
	    st.insert(arr[idx+N]);
	    idx+=1;
	}
	
	ll ret= 0;
	queue<ll> q;
	for(int i= idx + N - 1; i>= idx; i--){
	    q.push(i);
	    while(init[i]--){
	        ret += (q.front()-  i)*(q.front()-i);
	        q.pop();
	    }
	}
	
	cout<<ret;

    return 0;
}
