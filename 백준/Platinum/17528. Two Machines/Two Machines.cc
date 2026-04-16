//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector> //vector
#include<algorithm> //min,max

const int maxsize = 250 * 250;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> a;
    vector<int> b;
    vector<int> dp(maxsize+1, INF);

    dp[0] = 0;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        dp[0] += y;
    }
    for (int i = 0; i < N; i++) {
        for (int j = maxsize; j >= a[i]; j--) {
            if (dp[j - a[i]] != INF) {
                dp[j] = min(dp[j], dp[j - a[i]] - b[i]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < maxsize + 1; i++) {
        ans = min(ans, max(i, dp[i]));
    }
    cout << ans;


    return 0;
}


