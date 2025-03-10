#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin>>N;
	vector<int> cnt(3,0);
	for(int i=0; i<N;i++){
		string s;
		cin>>s;
		if(s.front()=='M') cnt[0]+=1;
		else if(s.front()=='Y') cnt[1]+=1;
		else cnt[2]+=1;
		cin>>s;
	}
	
	int mn = min(cnt[0], min(cnt[1],cnt[2]));
	cout<<mn<<endl;
	if(cnt[0] == mn) cout<<"Minjun"<<endl;
	if(cnt[1]==mn) cout<<"Yujung"<<endl;
	if(cnt[2]==mn) cout<<"Lammar"<<endl;
	
}