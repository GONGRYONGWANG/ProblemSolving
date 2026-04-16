//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string s;
    vector<int> pi;
    while (1) {
        getline(cin, s);
        if (s == ".") break;
        pi.clear();
        pi.resize(s.size(), 0);
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            while ((j > 0) && (s[i] != s[j])) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
                pi[i] = j;
            }
        }

        if (s.size() % (s.size()-pi[s.size() - 1])) {
            cout << 1;
        }
        else cout << s.size() / (s.size()-pi[s.size() - 1]);
        cout << endl;
        
    }
    return 0;
}