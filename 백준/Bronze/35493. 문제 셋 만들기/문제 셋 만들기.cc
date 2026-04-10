#include<bits/stdc++.h>
using namespace std;
 
 
void solve(int tc) {
    
    int N;
    cin >> N;
 
    int x;
    for (int i = 0; i < N; i++) cin >> x;
 
    if (N == 1 && x % 2) cout << "NO";
    else cout << "YES";
 
 
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
