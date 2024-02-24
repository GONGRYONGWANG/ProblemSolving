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
    stack<pii> st;
    st.push({1e9, 0});
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        while (st.top().first <= x) {
            st.pop();
        }
        cout << st.top().second << " ";
        st.push({ x,i });
    }
    return 0;
}