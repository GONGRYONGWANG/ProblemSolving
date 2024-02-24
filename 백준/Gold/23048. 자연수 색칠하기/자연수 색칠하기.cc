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

int prime[500001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        prime[i] = i;
    }
    for (int i = 2; i <= sqrt(N); i++) {
        if (prime[i]!=i) continue;
        for (int j = 2; i * j <= N; j++) {
            prime[i * j] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (prime[i] == i) ans += 1;
    }
    cout << ans<<endl;
    int cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (prime[i] == i) {
            prime[i] = cnt;
            cnt += 1;
        }
        else {
            prime[i] = prime[prime[i]];
        }
        cout << prime[i]<<" ";
    }

    return 0;
}