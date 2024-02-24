//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
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
    ll N, M;
    cin >> N >> M;
    N = N % (mod - 1);
    M = M % (mod - 1);
    cout << (powmod(2, N) + powmod(2, M) - 2) % mod;
    return 0;
}
