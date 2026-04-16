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

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, R, C;
    cin >> N >> R >> C;
    N = 1 << N;
    int ans = 0;
    while (N!=1){
        N  /= 2;
        if (R >= N) {
            R -= N;
            ans += 2 * N * N;
        }
        if (C >= N) {
            C -= N;
            ans += N * N;
        }
    }
    cout << ans;
    return 0;
}
