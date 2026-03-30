#include<bits/stdc++.h>
using namespace std;
 
unordered_set<int> st;
 
void solve(int tc) {
 
    if (tc == 1) {
        for (int i = 1; i < 10; i++) st.insert(i);
        for (int i = 1; i < 10000; i++) {
            string s = to_string(i);
            st.insert(stoi(s + s));
            for (int j = 0; j < 10; j++) {
                st.insert(stoi(s + char('0' + j) + s));
            }
        }
    }
 
    int N;
    cin >> N;
 
    int ret = 0;
    for (int x : st) {
        ret += st.count(N - x);
    }
 
    cout << ret << endl;
 
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}
