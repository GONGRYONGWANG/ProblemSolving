//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18


int DP[22][200001];
int dp(int i, int x) {
    if (DP[i][x] != 0) {
        return DP[i][x];
    }
    int ox = x;
    x = dp(i - 1, x);
    return DP[i][ox] = dp(i - 1, x); 
}
int f(int n, int x) {
    int i = 0;
    while (n != 0) {
        if (n % 2) {
            x = dp(i, x);
        }
        n /= 2;
        i++;
    }
    return x;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> DP[0][i];
    }
    int Q;
    cin >> Q;
    int n, x;
    for (int i = 0; i < Q; i++) {
        cin >> n >> x;
        cout << f(n, x)<<endl;
    }
    return 0;
}

