#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int arr[1000];
int mpf[1000001];
vector<int> prime;
 
void solve(int tc) {
 
    int N;
    cin >> N;
 
    mpf[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (!mpf[i]) {
            prime.push_back(i);
            mpf[i] = i;
        }
        for (int p : prime) {
            if (i * p > 1000000) break;
            mpf[i * p] = p;
            if (i % p == 0) break;
        }
    }
 
    for (int i = 0; i < N; i++) cin >> arr[i];
 
    int l = arr[0];
    for (int i = 1; i < N; i++) {
        l = lcm(l, arr[i]);
        if (mpf[l] != l) {
            cout << "YES" << endl << i + 1 << endl;
            for (int j = 0; j <= i; j++) cout << arr[j] << " ";
            return;
        }
    }
 
 
    cout << "NO";
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}
