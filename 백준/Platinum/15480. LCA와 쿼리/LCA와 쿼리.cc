//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


int N, M;
int parent[100001][18];
#include<vector> 
vector<int> edge[100001];
int depth[100001];
#include<queue>
queue<int> Q;



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    Q.push(1);
    for (int i = 1; i <= N; i++) {
        depth[i] = -1;
    }
    depth[1] = 0;
    while (!Q.empty()) {
        int node = Q.front();
        int d = depth[node];
        Q.pop();
        for (int i = 0; i < edge[node].size(); i++) {
            if (depth[edge[node][i]] == -1) {
                Q.push(edge[node][i]);
                depth[edge[node][i]] = d + 1;
                parent[edge[node][i]][0] = node;
            }
        }
    }

    //bottom-up으로 parent 채우기
    for (int i = 0; i < 17; i++) {
        for (int j = 2; j <= N; j++) {
            if (parent[j][i] != 0) {
                parent[j][i + 1] = parent[parent[j][i]][i];
            }
        }
    }

    cin >> M;
    int r, u, v;
    for (int i = 0; i < M; i++) {
        cin >> r >> u >> v;
        int ans1, ans2, ans3;
        int diff;
        a = r; b = u;
        if (depth[a] < depth[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        diff = depth[a] - depth[b];
        for (int j = 0; diff != 0; j++) {
            if (diff % 2) { a = parent[a][j]; }
            diff /= 2;
        }
        if (a != b) {
            for (int j = 17; j >= 0; j--) {
                if (parent[a][j] != 0 && parent[a][j] != parent[b][j]) {
                    a = parent[a][j];
                    b = parent[b][j];
                }
            }
            a = parent[a][0];
        }
        ans1 = a;

        a = u; b = v;
        if (depth[a] < depth[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        diff = depth[a] - depth[b];
        for (int j = 0; diff != 0; j++) {
            if (diff % 2) { a = parent[a][j]; }
            diff /= 2;
        }
        if (a != b) {
            for (int j = 17; j >= 0; j--) {
                if (parent[a][j] != 0 && parent[a][j] != parent[b][j]) {
                    a = parent[a][j];
                    b = parent[b][j];
                }
            }
            a = parent[a][0];
        }
        ans2 = a;

        a = r; b = v;
        if (depth[a] < depth[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        diff = depth[a] - depth[b];
        for (int j = 0; diff != 0; j++) {
            if (diff % 2) { a = parent[a][j]; }
            diff /= 2;
        }
        if (a != b) {
            for (int j = 17; j >= 0; j--) {
                if (parent[a][j] != 0 && parent[a][j] != parent[b][j]) {
                    a = parent[a][j];
                    b = parent[b][j];
                }
            }
            a = parent[a][0];
        }
        ans3 = a;

        if (ans1 == ans2) {
            cout << ans3 << endl;
        }
        else if (ans1 == ans3) {
            cout << ans2 << endl;
        }
        else {
            cout << ans1 << endl;
        }
    }

    return 0;
}

