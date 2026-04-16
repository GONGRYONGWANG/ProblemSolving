//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int DP[10001];
int dp(int x) {
    if (DP[x]) return DP[x];
    return dp(x-3) + (x/2+1);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    while (T--) {
        int N;
        cin >> N;
        cout << dp(N)<<endl;
    }
    return 0;
}