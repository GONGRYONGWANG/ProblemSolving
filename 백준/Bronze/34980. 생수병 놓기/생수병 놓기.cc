#include<bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;
    if (A == B) {
        cout << "Good";
        return 0;
    }

    int cnt = 0;
    for (char x : A) {
        cnt += (x == 'w');
    }
    for (char x : B) {
        cnt -= (x == 'w');
    }

    if (cnt > 0) cout << "Oryang";
    else if (cnt < 0) cout << "Manners maketh man";
    else cout << "Its fine";


    return 0;
}