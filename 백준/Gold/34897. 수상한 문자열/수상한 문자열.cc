#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int parent[400001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        parent[i + N] = i + N;
    }

    bool flag = true;
    while (M--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            while (l < r) {
                if (findp(r) == findp(l + N)) flag = false;
                parent[findp(r)] = findp(l);
                parent[findp(r + N)] = findp(l + N);
                l += 1; r -= 1;
            }
        }
        else {
            if (findp(l) == findp(r)) flag = false;
            parent[findp(l)] = findp(r + N);
            parent[findp(r)] = findp(l + N);
        }
    }

    if (!flag) {
        cout << "No";
        return;
    }

    cout << "Yes" << endl;

    vector<int> visited(2 * N + 1, -1);
    for (int i = 1; i <= N; i++) {
        if (visited[findp(i)] == -1) {
            visited[findp(i)] = 0;
            visited[findp(i + N)] = 1;
        }
        cout << char('A' + visited[findp(i)]);
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