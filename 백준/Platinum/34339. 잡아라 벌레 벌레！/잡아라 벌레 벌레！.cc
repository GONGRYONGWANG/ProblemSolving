#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#include<numbers>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("./dduk/10.in");ofs.open("output.txt");
#ifdef DEBUG
#define in ifs
#define out ofs
#else
#define in cin
#define out cout
#endif // DEBUG

#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
#define arrin(x,n) for(ll qwer=0;qwer<n;qwer++)cin>>x[qwer];
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF=1e18;
constexpr ll mod=1e9+7;
constexpr ll sz=201;
constexpr double pi=acos(-1);
ll d[9]= {1,-1,-1,0,1,1,0,-1,1};

using cd=complex<double>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

ll DP[101];

void solve(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N;i++) cin>>arr[i];
    int l= 0;
    DP[0]=1;
    ll ans =0;
    ll prv =  0;
    for(int i=0; i<N;i++){
        for(int j=100; j>=arr[i]; j--){
            DP[j] += DP[j-arr[i]];
        }
        if(DP[100]==0) {
            ans += prv;
            continue;
        }
        while(DP[100]!=0){
            for(int j=arr[l]; j<=100; j++){
                DP[j] -= DP[j-arr[l]];
            }
            l +=1;
        }
        prv = l;
        ans +=prv;
    }

    cout<<ans;




}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
