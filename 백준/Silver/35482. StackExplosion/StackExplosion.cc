#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
 
void solve(int tc) {
 
    
    int N;
    cin >> N;
    vector<pll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first;
    for (int i = 0; i < N; i++) cin >> arr[i].second;
    
    for (int i = 0; i < N; i++) arr[i].first -= arr[i].second;
 
    sort(arr.rbegin(), arr.rend());
 
    ll total = 0;
    while (!arr.empty() && arr.back().first < total) {
        ll ext = 0;
        while (!arr.empty() && arr.back().first < total) {
            ext += (arr.back().second + total) / 2;
            arr.pop_back();
        }
        total += ext;
    }
 
    cout << N - arr.size();
 
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
