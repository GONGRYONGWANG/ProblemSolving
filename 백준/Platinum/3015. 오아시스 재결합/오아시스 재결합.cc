//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    ll ans=0;
    stack<pii> st;
    int len = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        while (!st.empty() && x > st.top().first) {
            ans += st.top().second;
            st.pop();
        }

        if (st.empty()) {
            st.push({ x,1 });
            continue;
        }

        if (x == st.top().first) {
            ans += st.top().second;
            if (st.size() != 1) ans += 1;
            st.top().second += 1;
        }
        else {
            ans += 1;
            st.push({ x,1 });
        }
    }
    cout << ans;
    return 0;
}