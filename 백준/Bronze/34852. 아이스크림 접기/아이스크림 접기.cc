#include<bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
#define ll long long
 
 
void solve(int tc) {
 
    ll N; cin >> N;
    cout << fixed;
    cout.precision(10);
    cout << (N - N / cos(pi / 12) / sqrt(2)) * (N - N / sqrt(3));
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