//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<utility>
#include<algorithm>

void MAIN() {
    int N;
    cin >> N;
    vector<pair<int, int>> fcs;
    vector<int> dp(100001,INF);

    int a, b;
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        fcs.push_back({ a,b });
        dp[0] += b;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 100000; j >= fcs[i].first; j--) {
            if (dp[j - fcs[i].first] != INF) {
                dp[j] = min(dp[j], dp[j - fcs[i].first] - fcs[i].second);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 100001; i++) {
        ans = min(ans, max(i, dp[i]));
    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        MAIN();
    }
    
    
    return 0;
}


