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
    queue<pll>q;
    ll A, B;
    cin >> A>>B;
    q.push({A,0});
    while (!q.empty()) {
        A = q.front().first;
        ll t = q.front().second;
        q.pop();
        if (A == B) {
            cout << t+1;
            return 0;
        }
        if (A > B) continue;
        q.push({ 2 * A,t + 1 });
        q.push({ 10 * A + 1,t + 1 });
    }
    cout << -1;
    return 0;
}
