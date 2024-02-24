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
    int N, M;
    cin >> N >> M;
    vector<ll> mod(M,0);
    mod[0] = 1;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum = (sum + x) % M;
        mod[sum] += 1;
    }
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ans += mod[i] * (mod[i] - 1) / 2;
    }
    cout << ans;
    return 0;
}