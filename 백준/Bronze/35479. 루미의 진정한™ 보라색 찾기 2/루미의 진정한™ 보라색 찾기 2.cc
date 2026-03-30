#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define endl "\n"
 
void solve(int tc) {
 
    ld R, G, B;
    cin >> R >> G >> B;
 
    R /= 255; G /= 255; B /= 255;
 
    ld K = 1 - max(max(R, G), B);
    if(K==1){
        cout<<"0 0 0 1";
        return;
    }
 
    cout << fixed;
    cout.precision(10);
    cout << (1 - R - K) / (1 - K) << " " << (1 - G - K) / (1 - K) << " " << (1 - B - K) / (1 - K) << " " << K;
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
