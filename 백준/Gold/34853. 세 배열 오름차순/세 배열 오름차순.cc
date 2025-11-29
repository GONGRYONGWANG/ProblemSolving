#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int> arr[100001];
 
void solve(int tc) {
 
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int K; cin >> K;
        arr[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> arr[i][j];
        }
        sort(arr[i].begin(), arr[i].end());
    }
 
    while (Q--) {
        int A, B, C, j;
        cin >> A >> B >> C >> j;
        int l = 1;
        int r = 1e9;
        while (l < r) {
            int m = (l + r) / 2;
            int ret = 0;
            ret += upper_bound(arr[A].begin(), arr[A].end(), m) - arr[A].begin();
            ret += upper_bound(arr[B].begin(), arr[B].end(), m) - arr[B].begin();
            ret += upper_bound(arr[C].begin(), arr[C].end(), m) - arr[C].begin();
            if (ret >= j) r = m;
            else l = m + 1;
        }
        cout << l << endl;
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