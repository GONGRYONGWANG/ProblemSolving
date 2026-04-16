//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int DP[10][26];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int idx=1;
        for (int j = 0; j < K; j++) {
            if (DP[j][(int)s[j] - 97]) {
                idx = max(idx, DP[j][(int)s[j] - 97] + 1);
            }
        }
        for (int j = 0; j < K; j++) {
            DP[j][(int)s[j] - 97] = idx;
        }
        ans = max(ans, idx);
    }
    cout << N - ans;

    return 0;
}