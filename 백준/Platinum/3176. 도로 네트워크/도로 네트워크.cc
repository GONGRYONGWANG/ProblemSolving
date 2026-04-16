//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9



int N,K;
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
pair<int, pair<int,int>> parent[100001][18];
int depth[100001];
vector<pair<int, int>> edge[100001];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int a, b, c;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }
    queue<int> Q;
    Q.push(1);
    for (int i = 1; i <= N; i++) {
        depth[i] = -1;
    }
    depth[1] = 0;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (int i = 0; i < edge[node].size(); i++) {
            if (depth[edge[node][i].first] == -1) {
                parent[edge[node][i].first][0] = { node, {edge[node][i].second,edge[node][i].second }};
                Q.push(edge[node][i].first);
                depth[edge[node][i].first] = depth[node] + 1;
            }
        }
    }





    for (int i = 0; i < 17; i++) {
        for (int j = 1; j <= N; j++) {
            if (parent[j][i].first != 0) {
                parent[j][i + 1].first = parent[parent[j][i].first][i].first;
                parent[j][i + 1].second.first = min(parent[parent[j][i].first][i].second.first, parent[j][i].second.first);
                parent[j][i + 1].second.second = max(parent[parent[j][i].first][i].second.second, parent[j][i].second.second);
            }
        }
    }
    
   
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        pair<int, int> ans = {INF,0};
        if (depth[a] < depth[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        int diff = depth[a] - depth[b];
        for (int j = 0; diff != 0; j++) {
            if (diff % 2) { 
                ans.first = min(ans.first, parent[a][j].second.first);
                ans.second = max(ans.second, parent[a][j].second.second);
                a = parent[a][j].first; 
            }
            diff /= 2;
        }

        if (a != b) {
            for (int j = 17; j >= 0; j--) {
                if (parent[a][j].first != 0 && parent[a][j].first != parent[b][j].first) {
                    ans.first = min(ans.first, parent[a][j].second.first);
                    ans.first = min(ans.first, parent[b][j].second.first);
                    ans.second = max(ans.second, parent[a][j].second.second);
                    ans.second = max(ans.second, parent[b][j].second.second);
                    a = parent[a][j].first;
                    b = parent[b][j].first;
                }
            }
            ans.first = min(ans.first, parent[a][0].second.first);
            ans.first = min(ans.first, parent[b][0].second.first);
            ans.second = max(ans.second, parent[a][0].second.second);
            ans.second = max(ans.second, parent[b][0].second.second);
        }
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}

