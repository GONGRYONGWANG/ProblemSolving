//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<string>

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string s;
    cin >> s;
    int ans;
    bool state;
    if (s[0] == 'd') {
        ans = 10;
        state = 0;
    }
    else {
        ans = 26;
        state = 1;
    }
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'd') {
            if (!state) {
                ans *= 9;
            }
            else {
                ans *= 10;
            }
            state = 0;
        }
        else {
            if (state) {
                ans *= 25;
            }
            else {
                ans *= 26;
            }
            state = 1;
        }
    }
    cout << ans;

    return 0;
}

