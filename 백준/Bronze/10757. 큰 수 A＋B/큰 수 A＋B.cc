#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<string>
#include<vector>
#include<algorithm>
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string A, B;
    cin >> A >> B;
    int sum;
    int a, b;
    int state = 0;
    for (int i = 0; i < max(A.length(), B.length()); i++) {
        if (i < A.length()) { a = (int)A[A.length()-1-i]-48; }
        else { a = 0; }
        if (i < B.length()) { b = (int)B[B.length() - 1 - i]-48; }
        else { b = 0; }
        sum = a + b + state;
        state = 0;
        if (sum >= 10) {
            sum -= 10;
            state = 1;
        }
        v.push_back(sum);
    }
    if (state == 1) {
        cout << 1;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }
    return 0;
}

