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

ll mod = 1000000007;
ll powmod(ll x, ll y) {
    ll rt = 1;
    while (y) {
        if (y % 2) {
            rt = rt * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }

    return rt;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> menu;
    ll x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        menu.push_back(x);
    }
    sort(menu.begin(), menu.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (powmod(2, i)- powmod(2, N - 1 - i))*menu[i]%mod;
        ans %= mod;
    }
    cout << (ans+mod)%mod;
    return 0;
}