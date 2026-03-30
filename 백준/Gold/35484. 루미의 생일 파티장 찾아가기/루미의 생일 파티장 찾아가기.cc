#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
 
 
void solve(int tc) {
 
 
    int N;
    cin >> N;
 
    int x;
    int l = 1; int r = N / 2;
    while (l < r) {
        int m = (l + r) / 2;
        cout << "? 1 " << N << " " << m << endl << flush;
        cin >> x;
        if (x) r = m;
        else l = m + 1;
    }
 
    cout << "? 0 " << N << " " << l << endl << flush;
    cin >> x;
 
    cout << "! ";
    if (x) cout << 2 * l;
    else cout << 2 * l + 1;
    cout << flush;
 
 
 
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
