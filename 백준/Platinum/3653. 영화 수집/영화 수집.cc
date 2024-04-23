#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


void solve(){
        
    int N,M;
    cin>>N>>M;
    vector<int> arr(N+1);
    for(int i=1; i<=N;i++){
        arr[i]=i;
    }
    ordered_set os;
    for(int i=1;i<=N;i++){
        os.insert(i);
    }
    
    while(M--){
        int x;
        cin>>x;
        cout<<os.order_of_key(arr[x])<<" ";
        os.erase(arr[x]);
        arr[x]= *os.begin() - 1;
        os.insert(arr[x]);
    }
    cout<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
}