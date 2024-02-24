//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9
#include<string>
#include<stack>
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    string s;
    stack<char> st;
    getline(cin, s);
    while (T--) {
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                st.push(s[i]);
            }
            else {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << " ";
            }
        }
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }

    return 0;
}

