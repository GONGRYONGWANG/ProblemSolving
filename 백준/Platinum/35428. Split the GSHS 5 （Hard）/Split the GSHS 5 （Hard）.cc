#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define INF ll(2e18)
 
ll T[300001];
ll F[300001];
 
ll DP[300001];
ll L[300001];
 
multiset<ll> st;
deque<int> q;
 
void pop() {
    st.erase(st.find(DP[L[q.front()] - 1] + 2 * (F[q.front()] - 1)));
    L[q.front()] += 1;
    if (L[q.front()] > q.front()) {
        q.pop_front();
        return;
    }
    st.insert(DP[L[q.front()] - 1] + 2 * (F[q.front()] - 1));
}
 
void solve(int tc) {
 
    int N, M, C;
    cin >> N >> M >> C;
 
    
 
 
    for (int i = 1; i < N; i++) {
        cin >> T[i] >> F[i];
        L[i] = i;
        while (!q.empty() && F[i] >= F[q.back()]) {
            L[i] = L[q.back()];
            st.erase(st.find(DP[L[q.back()] - 1] + 2 * (F[q.back()] - 1)));
            q.pop_back();
        }
        q.push_back(i);
        st.insert(DP[L[i] - 1] + (F[i] - 1) * 2);
 
        if (L[q.front()] == i - C) pop();
        while (L[q.front()] != i && DP[L[q.front()]] <= T[i]) pop();
 
        st.erase(st.find(DP[L[q.front()] - 1] + (F[q.front()] - 1) * 2));
        DP[L[q.front()] - 1] = max(DP[L[q.front()] - 1], T[i]);
        st.insert(DP[L[q.front()] - 1] + (F[q.front()] - 1) * 2);
 
        DP[i] = *st.begin();
    }
 
    cin >> T[N] >> F[N];
 
    ll ret = INF;
    ll mx = 1;
    for (int i = N - 1; i >= N - C; i--) {
        mx = max(mx, F[i+1]);
        ret = min(ret, max(T[N], DP[i]) + mx - 1);
    }
 
    cout << ret;
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}
