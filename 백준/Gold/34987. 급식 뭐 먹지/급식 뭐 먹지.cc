#include<bits/stdc++.h>
using namespace std;

int arr[1000002];

void solve(int tc) {

    int N, C;
    cin >> N >> C;

    while (N--) {
        int a, b;
        cin >> a >> b;
        if (a + b > C) continue;
        arr[a] += 1;
        arr[C - b + 1] -= 1;
    }

    int ret = 0;
    int psum = 0;
    for (int i = 0; i <= 1000000; i++) {
        psum += arr[i];
        ret = max(ret, psum);
    }

    cout << ret;

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