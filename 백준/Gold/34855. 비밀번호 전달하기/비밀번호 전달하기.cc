#include<bits/stdc++.h>
using namespace std;
 
void solve(int tc) {
    
    int t;
    cin >> t;
    vector<int> arr(6);
    for (int& x : arr) cin >> x;
 
    vector<bool> v(64,false);
    for (int x : arr) {
        for (int y : arr) {
            v[(x - y + 64) % 64] = true;
        }
    }
 
    int d = 0;
    while (v[d]) d++;
 
    for (int x : arr) {
        if (t == 1) x += d;
        else x -= d;
        x = (x + 64) % 64;
        if (x == 0) x = 64;
        cout << x << " ";
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