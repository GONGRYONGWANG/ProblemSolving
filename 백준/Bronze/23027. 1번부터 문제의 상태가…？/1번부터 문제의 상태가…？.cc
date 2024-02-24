//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<string>
#include<vector>

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string S;
    cin >> S;
    bool check_a = 0;
    bool check_b = 0;
    bool check_c = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'A') {
            check_a = 1;
        }
        else if (S[i] == 'B') {
            check_b = 1;
        }
        else if (S[i] == 'C') {
            check_c = 1;
        }
    }
    if (check_a) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'B' || S[i] == 'C' || S[i] == 'D' || S[i] == 'F') {
                cout << "A";
            }
            else cout << S[i];
        }
        return 0;
    }
    if (check_b) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'C' || S[i] == 'D' || S[i] == 'F') {
                cout << "B";
            }
            else {
                cout << S[i];
            }
        }
        return 0;
    }
    if (check_c) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'D' || S[i] == 'F') {
                cout << "C";
            }
            else cout << S[i];
        }
        return 0;
    }
    for (int i = 0; i < S.length(); i++) {
        cout << "A";
    }

    return 0;
}

