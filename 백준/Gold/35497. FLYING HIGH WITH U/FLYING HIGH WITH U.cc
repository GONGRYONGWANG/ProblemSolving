#include<bits/stdc++.h>
using namespace std;
 
void solve(int tc) {
 
    int N;
    cin >> N;
 
    stack<int> st;
    st.push(0);
    int ret = 0;
    while (N--){
        int x; cin >> x;
        ret += max(0, x - st.top());
        while (!st.empty() && st.top() >= x) st.pop();
        st.push(x);
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
