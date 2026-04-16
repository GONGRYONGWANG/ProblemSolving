#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
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
typedef int ll;
typedef long double ld;
ll d[5]= {1,0,-1,0,1};

vector<ll> A;
vector<ll> B;
int N,M;
ll DP[3001][102][102][2];
ll dp(int x , int l , int r , int p){
    
    if(DP[x][l][r][p]) return DP[x][l][r][p];
    
    if(x==N){
        if(l>r) return 0;
        
        DP[x][l][r][p] = dp(x,l+1,r,0);
        
        if(p==0){
            DP[x][l][r][p] = max(DP[x][l][r][p],dp(x,l,r-1,1)+B[r]);
        }
        return DP[x][l][r][p];
    }

    if(l>r){
        DP[x][l][r][p] = dp(x+1,l,r,0);
        if(p==0){
            DP[x][l][r][p] = max(DP[x][l][r][p], dp(x+1,l,r,1)+A[x]);
        }
        return DP[x][l][r][p];
    }


    DP[x][l][r][p] = max(dp(x+1,l,r,0), dp(x,l+1,r,0));
    
    if(p==0){
        DP[x][l][r][p] = max(DP[x][l][r][p], dp(x+1,l,r,1)+A[x]);
        DP[x][l][r][p] = max(DP[x][l][r][p], dp(x,l,r-1,1)+B[r]);
    }

    return DP[x][l][r][p];
}
// 6e7

void solve(){


    cin>>N;
    A.resize(N);
    for(int i=0; i<N;i++){
        cin>>A[i];
    }

    cin>>M;
    B.resize(M+1);
    for(int i=1; i<=M;i++){
        cin>>B[i];
    }
    sort(B.begin()+1,B.end());


    cout<<dp(0,1,M,0);


}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
