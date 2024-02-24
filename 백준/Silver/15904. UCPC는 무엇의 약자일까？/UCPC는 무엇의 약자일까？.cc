#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<string>
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string s;
    getline(cin, s);
    string UCPC = "UCPC";
    int search = 0;
    int idx = 0;
    while (idx < s.length()) {
        if (s[idx] == UCPC[search]) {
            search++;
        }
        idx++;
        if (search == 4) {
            cout << "I love UCPC"; return 0;
        }
    }
    cout << "I hate UCPC";



    return 0;
}