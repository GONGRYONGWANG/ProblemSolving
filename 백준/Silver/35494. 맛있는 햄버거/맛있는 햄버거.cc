#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int cnt[500001];
int arr[500001];
 
void solve(int tc) {
 
    int N;
    cin >> N;
 
    int mx = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]] += 1;
        mx = max(mx, arr[i]);
    }
 
    ll ret = 0;
    for (int i = N - 1; i >= 0; i--) {
        ret += mx;
        cnt[arr[i]] -= 1;
        while (cnt[mx] == 0) mx -= 1;
    }
 
    cout << ((ret % 3 == 0) ? "Delicious!" : "Oh My God!");
 
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
