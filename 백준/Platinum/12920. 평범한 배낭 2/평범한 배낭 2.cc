//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<algorithm>
int N,M;
long long DP[10001];

vector<int> weight;
vector<int> val;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int V, C, K;
    for (int i = 0; i < N; i++) {
        cin >> V >> C >> K;
        for (int i = 1; K > 0; i <<= 1) {
            const int ix = min(i, K);
            weight.push_back(V * ix);
            val.push_back(C * ix);
            K -= ix;
        }
    }

    for (int i = 0; i <= M; i++) {
        DP[i] = -1;
    }
    DP[0] = 0;
    for (int i = 0; i < weight.size(); i++) {
        for (int j = M; j >= 0; j--) {
            if (DP[j] != -1 && j+weight[i]<=M) {
                DP[j + weight[i]] = max(DP[j + weight[i]], DP[j] + val[i]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= M; i++) {
        ans = max(ans, DP[i]);
    }
    cout << ans;
    return 0;
}

