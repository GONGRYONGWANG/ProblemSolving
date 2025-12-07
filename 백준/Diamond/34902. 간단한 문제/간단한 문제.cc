#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<bool> visited(N, false);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        x -= 1;
        visited[x] = true;
        if (visited[(x + 1) % N]) cnt += 1;
    }


    int cnt2 = 0;
    visited.clear();
    visited.resize(N, false);
    while (M--) {
        int x; cin >> x;
        x -= 1;
        visited[x] = true;
        if (visited[(x + 1)% N]) cnt2 += 1;
    }

    int ext = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        if (visited[(i + 1) % N]) cnt2 += 1;
        else ext += 1;
    }

    if (cnt2 <= cnt && cnt2 + ext >= cnt) {
        cout << "Yes";
    }
    else cout << "No";
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}