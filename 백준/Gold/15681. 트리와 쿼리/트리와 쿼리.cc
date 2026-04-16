#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9
#include<vector>
vector<int> line[100001];
int ans[100001];
int N, R, Q;
int answer(int node) {
    ans[node] = 1;
    for (int i = 0; i < line[node].size(); i++) {
        if (ans[line[node][i]] == -1) {
            ans[node] += answer(line[node][i]);
        }
    }
    return ans[node];
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> R >> Q;
    for (int i = 1; i <= N; i++) {
        ans[i] = -1;
    }
    int a, b;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }
    answer(R);
    int u;
    for (int i = 0; i < Q; i++) {
        cin >> u;
        cout << ans[u] << endl;
    }
    return 0;
}
