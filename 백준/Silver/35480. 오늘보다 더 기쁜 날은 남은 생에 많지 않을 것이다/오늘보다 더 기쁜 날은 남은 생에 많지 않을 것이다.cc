#include<bits/stdc++.h>
using namespace std;
 
 
void solve(int tc) {
 
    vector<int> s, e;
    int y, m, d;
    cin >> y >> m >> d;
    s = { y,m,d };
    cin >> y >> m >> d;
    e = { y,m,d };
 
    int N;
    cin >> N;
    vector<vector<int>> arr(N,vector<int>(3));
 
    int thres = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        if (arr[i][1] == s[1] && arr[i][2] == s[2]) {
            thres = s[0] - arr[i][0] + 1;
        }
    }
 
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int x = 1;
        while (arr[i] <= e) {
            if (arr[i] > s && x > thres) ret += 1;
            arr[i][0] += 1;
            x += 1;
        }
    }
 
    cout << ret;
 
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
