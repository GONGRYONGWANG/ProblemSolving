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
    string s;
    string ex;
    cin >> s;
    cin >> ex;
    vector<pii> st;
    st.push_back({ -1, -1 });
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ex[st.back().second + 1]) {
            st.push_back({ i, st.back().second + 1 });
            if (st.back().second == ex.length() - 1) {
                while (st.back().second!=0) {
                    st.pop_back();
                }
                st.pop_back();
            }
        }
        else if (s[i] == ex[0]) {
            st.push_back({ i,0 });
        }
        else {
            st.push_back({ i,-1 });
        }
    }

    if (st.size() == 1) {
        cout << "FRULA";
    }
    for (int i = 1; i < st.size(); i++) {
        cout << s[st[i].first];
    }
    return 0;
}