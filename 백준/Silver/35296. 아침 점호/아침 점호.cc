#include<bits/stdc++.h>
using namespace std;
 
bool arr[10001];
 
void solve(int tc) {
    
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c;
            cin >> c;
            arr[i + N * (j - 1)] = (c == 'O');
        }
    }
 
    vector<vector<int>> ret;
 
    for (int i = 1; i <= N * M; i++) {
        if (arr[i]) continue;
        if (i != N * M && (i % N != 0 || N == 1) && !arr[i + 1]) {
            arr[i] = arr[i + 1] = true;
            ret.push_back({ 2,i,i + 1 });
        }
        else ret.push_back({ 1,i });
    }
 
    cout << ret.size() << endl;
    for (auto& v : ret) {
        for (int& x : v) cout << x << " ";
        cout << endl;
    }
 
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
