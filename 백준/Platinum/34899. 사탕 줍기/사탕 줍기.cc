#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl "\n"

ll comb[401][401];

int board[200][200];

void solve(int tc){
        
    ll x;
    cin>>x;
    
    map<ll, pii> m;
    for(int i=0;i<=400;i++){
        comb[i][0] = 1;
        for(int j=1; j<=i; j++){
            comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
            comb[i][j] = min(comb[i][j], x+1);
            if(comb[i][j]>x) continue;
            int a = min(i-j,j) + 1; int b = max(i-j,j)+1;
            if(b>=199) continue;
            if(!m.count(comb[i][j])) m[comb[i][j]] = {a,b};
            else if(a < m[comb[i][j]].first) m[comb[i][j]] = {a,b};
        }
    }
    
    
    for(int j=0; j<200;j++){
        board[199][j] = 1;
    }
    
    int idx=0;
    while(x!=0){
        auto it = prev(m.upper_bound(x));
        auto [a,b] = it->second;
        x -= it->first;
        for(int i=0; i<b;i++){
            for(int j=idx; j<idx+a;j++){
                board[i][j] = 1;
            }
        }
        for(int i=0; i<200;i++){
            board[i][idx+a-1] = 1;
        }
        idx += a;
        board[0][idx] = 1;
        idx+=1;
    }
    
    cout<<200<<" "<<200<<endl;
    for(int i=0; i<200;i++){
        for(int j=0; j<200;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}