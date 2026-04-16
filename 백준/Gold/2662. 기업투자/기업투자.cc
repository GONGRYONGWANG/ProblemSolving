//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<algorithm>
int N, M;
int DP[301];
int val[20][301];
int invest[301][20];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        for (int j = 0; j < M; j++) {
            cin >> val[j][x];
        }
    }
    for (int i = 0; i <= N; i++) {
        DP[i] = -1;
    }
    DP[0] = 0;
    for (int i = 0; i < M; i++) {
        for (int j = N; j >= 0; j--) {
            if (DP[j] != -1) {
                for (int k = 1; k <= N-j; k++) {
                    if (DP[j + k] < DP[j] + val[i][k]) {
                        DP[j + k] = DP[j] + val[i][k];
                        for (int m = 0; m < 20; m++) {
                            invest[j + k][m] = invest[j][m];
                        }
                        invest[j+k][i] = k;
                    }
                }
            }
        }
    }
    int ans = 0;
    int ansidx = 0;
    for (int i = 0; i <= N; i++) {
        if (ans < DP[i]) {
            ans = DP[i];
            ansidx = i;
        }
        ans = max(ans, DP[i]);
    }
    cout <<  ans<<endl;
    for (int i = 0; i < M; i++) {
        cout << invest[ansidx][i] << " ";
    }
    return 0;
}

