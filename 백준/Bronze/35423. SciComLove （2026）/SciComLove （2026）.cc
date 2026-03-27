#include<bits/stdc++.h>
using namespace std;
 
void solve(int tc) {
 
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (char& c : s) {
        x += (c == 'S');
        y += (c == 'L');
    }
 
    while (x--) cout << "SciCom";
    while (y--) cout << "Love";
 
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
