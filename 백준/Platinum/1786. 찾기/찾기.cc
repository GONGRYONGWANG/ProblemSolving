//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define INF (1<<32)
#define inf 1e9
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;
#define fi first
#define se second

string t, s;
vector<int> pi;
vector<int> result;


void getPi() {
    pi.resize(s.size(),0);
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
}

void kmp() {
    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        while ((j > 0) && (t[i] != s[j])) {
            j = pi[j - 1];
        }
        if (t[i] == s[j]) {
            if (j == s.size() - 1) {
                result.push_back(i - s.size() + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    getline(cin, t);
    getline(cin, s);
    getPi();
    kmp();
    cout << result.size()<<endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] + 1<<" ";
    }

    return 0;
}