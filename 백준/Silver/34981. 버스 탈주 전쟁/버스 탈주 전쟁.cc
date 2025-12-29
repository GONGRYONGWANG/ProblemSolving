#include<bits/stdc++.h>
using namespace std;



void solve(int tc) {

    int X, Y;
    cin >> X >> Y;
    int cur = X * 60 + Y;
    vector<int> arr;
    int N;
    cin >> N;
    while (N--) {
        int a, b, c;
        cin >> a >> b >> c;
        int s = a * 60 + b;
        for (int i = s; i < 24 * 60; i += c) {
            arr.push_back(i);
        }
        arr.push_back(s + 24 * 60);
    }

    sort(arr.begin(), arr.end());
    int ret = *lower_bound(arr.begin(), arr.end(), cur);
    cout << setw(2) << setfill('0') << ret / 60 % 24 << ":" << setw(2) << setfill('0') << ret % 60;
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