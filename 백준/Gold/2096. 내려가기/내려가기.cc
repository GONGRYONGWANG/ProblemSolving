//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    vector<pii> prv(5);
    vector<pii> cur(5);
    cin >> N;
    prv[0] = { 0,1e9 }; prv[4] = { 0,1e9 };
    for (int j = 1; j <= 3; j++) {
        prv[j] = { 0,0 };
    }
    for (int i = 0; i < N; i++) {
        cur[0] = { 0,1e9 }; cur[4] = { 0,1e9 };
        for (int j = 1; j <= 3; j++) {
            int x;
            cin >> x;
            cur[j] = { x + max(max(prv[j-1].first,prv[j].first),prv[j+1].first), x + min(min(prv[j-1].second,prv[j].second),prv[j+1].second) };
        }
        prv = cur;
    }
    int ans1 = 0;
    int ans2 = 1e9;
    for (int j = 1; j <= 3; j++) {
        ans1 = max(ans1, cur[j].first);
        ans2 = min(ans2, cur[j].second);
    }
    cout << ans1 << " " << ans2;

    return 0;
}