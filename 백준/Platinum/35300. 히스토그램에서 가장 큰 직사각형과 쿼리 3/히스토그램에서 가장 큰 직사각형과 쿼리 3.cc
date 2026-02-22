#include<bits/stdc++.h>
using namespace std;
 
#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
 
 
int A[51];
 
void solve(int tc) {
 
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = i + 1;
 
    for (int i = 0; i < 10000; i++) {
        shuffle(arr.begin(), arr.end(), gen);
        cout << "? ";
        for (int& x : arr) cout << x << " ";
        cout << endl << flush;
        int l, r, h;
        cin >> l >> r >> h;
        for (int j = l; j <= r; j++) {
            A[arr[j - 1]] = max(h, A[arr[j - 1]]);
        }
    }
 
    for (int j = 1; j <= N; j++) {
        if (A[j] == N / 2 + 1) {
            cout << "! "<< j << endl << flush;
            return;
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}
