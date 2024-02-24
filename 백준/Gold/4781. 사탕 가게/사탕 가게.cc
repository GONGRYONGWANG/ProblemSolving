//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N, M;
#include<algorithm>
int DP[10001];
int val[5000];
int cost[5000];
void TEST() {
    for (int i = 0; i <= M; i++) {
        DP[i] = -1;
    }
    DP[0] = 0;
    int c;
    double p;
    for (int i = 0; i < N; i++) {
        cin >> c >> p;
        val[i] = c;
        cost[i] = int(100 * p+0.5);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (DP[j] != -1 && j + cost[i] <= M) {
                DP[j + cost[i]] = max(DP[j + cost[i]], DP[j] + val[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        ans = max(ans, DP[i]);
    }
    cout << ans << endl;

    return;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    double m;
    while (1) {
        cin >> N >> m;
        M = m * 100 + 0.5;
        if (N == 0 && M==0) { return 0; }
        TEST();
    }
    return 0;
}

