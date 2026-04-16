//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll X, Y;
    cin >> X >> Y;
    ll Z = Y * 100 / X;
    if (Z >= 99) {
        cout << -1; return 0;
    }
    ll ans = ((Z + 1) * X - 100 * Y) / (99 - Z);
    if (((Z + 1) * X - 100 * Y) % (99 - Z)) {
        ans += 1;
    }
    cout << ans;
    
    
    return 0;
}

