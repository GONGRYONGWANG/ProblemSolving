#include<bits/stdc++.h>
using namespace std;

bool adj[26][26];

void solve(int tc) {

    int N;
    cin >> N;
    while (N--) {
        char x; cin >> x;
        int m; cin >> m;
        while (m--) {
            char y;
            cin >> y;
            adj[x - 'a'][y - 'a'] = true;
        }
    }

    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
        if (!adj[s[i] - 'a'][s[i + 1] - 'a']) {
            cout << "no";
            return;
        }
    }

    cout << "yes";
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