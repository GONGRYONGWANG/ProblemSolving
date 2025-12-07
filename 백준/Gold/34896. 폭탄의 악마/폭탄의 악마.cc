#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 1000000007;

void solve(int tc) {

    int N;
    cin >> N;

    vector<pii> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first;
    for (int i = 0; i < N; i++) cin >> arr[i].second;
    sort(arr.begin(), arr.end());
    
    int B;
    cin >> B;

    int l = 1;
    int r = inf;
    while (l < r) {
        int m = (l + r) / 2;

        int total = 0;
        int mn = arr[0].second;
        for (int i = 1; i < N; i++) {
            if (arr[i].first <= arr[i - 1].first + m) {
                mn = min(mn, arr[i].second);
            }
            else {
                total += mn;
                mn = arr[i].second;
            }
        }
        total += mn;

        if (total <= B) r = m;
        else l = m + 1;
    }

    cout << l;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}