//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N;
int DP[100001][2];
int val[100001];
#include<algorithm>
int dp(int idx, bool x) {
    if (idx >= N) {
        return 0;
    }
    if (DP[idx][x] != -1) {
        return DP[idx][x];
    }
    if (x == 0) {
        return DP[idx][x] = max(val[idx] + dp(idx + 1, 1), dp(idx + 1, 0));
    }
    return DP[idx][x] = max(val[idx] / 2 + dp(idx + 2, 0), dp(idx + 1, 0));
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        DP[i][0] = -1;
        DP[i][1] = -1;
        cin >> val[i];
    }
    cout << dp(0, 0);
    return 0;
}

