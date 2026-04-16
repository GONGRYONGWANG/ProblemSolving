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

ll arr1[20];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        for (int i = 0; i <= 19; i++) {
            if ((x | (1 << i)) == x) {
                arr1[i] += 1;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 19; i++) {
        ans += (arr1[i] * (N-arr1[i]))*(1<<i);
    }
    cout << ans;
    return 0;
}