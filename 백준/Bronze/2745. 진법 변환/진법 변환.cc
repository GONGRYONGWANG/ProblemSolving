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
    string N;
    int B;
    cin >> N >> B;
    int ans = 0;
    int mul = pow(B, N.length() - 1);
    for (int i = 0; i < N.length(); i++) {
        char x = N[i];
        if ((int)x >= 65) {
            ans += mul * ((int)x - 55);
        }
        else {
            ans += mul * ((int)x - 48);
        }
        mul /= B;
    }
    cout << ans;
    return 0;
}