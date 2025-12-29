#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& x : arr) cin >> x;
    for (int i = 0; i < N / 2; i++) {
        bool flag = true;
        for (int j = 0; j <= i; j++) {
            flag &= (arr[j] == arr[N - 1 - i + j]);
        }
        if (flag) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";

    return 0;
}