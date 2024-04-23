#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N;
    cin>>N;
    rope<int> r;
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        r.insert(r.size()-x,i);
    }
    for(auto iter=r.begin(); iter!=r.end(); iter++){
        cout<<*iter<<" ";
    }

    return 0;
}