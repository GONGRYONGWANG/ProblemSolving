#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18



int N, M, K, S, T;
#include<vector>
#include<utility>
#include<algorithm>
vector<pair<int, int>> course[100001];
long long dp[100001][11];
long long DP(int node, int lift) {
    if (dp[node][lift] != -1) {
        return dp[node][lift];
    }
    long long result = -INF;
    if (node == T) {
        result = 0;
    }
    for (int i = 0; i < course[node].size(); i++) {
        if (course[node][i].second != 0) {
            result = max(result, DP(course[node][i].first, lift) + course[node][i].second);
        }
        else if(lift!=0){
            result = max(result, DP(course[node][i].first, lift - 1));
        }
    }
    return dp[node][lift] = result;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M >> K >> S >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -1;
        }
    }
    int a, b,t;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        course[a].push_back({ b,t });
        course[b].push_back({ a,0 });
    }
    long long ans = DP(S, K);
    if (ans < 0) {
        cout << -1; return 0;
    }
    cout << ans;
    return 0;
}

