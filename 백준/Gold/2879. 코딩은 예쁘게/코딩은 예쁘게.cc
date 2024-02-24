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

int v[1000];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v[i] = -x;
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        v[i] += x;
    }
    int ans = 0;
    int prv = 0;
    int cur;
    for (int i = 0; i < N; i++) {
        cur = v[i];
        if (cur * prv < 0) {
            ans += abs(cur);
        }
        else if (cur > 0 && cur>prv) {
            ans += cur - prv;
        }
        else if (cur < 0 && cur < prv) {
            ans += prv - cur;
        }
        prv = cur;
    }
    cout << ans;
    return 0;
}
