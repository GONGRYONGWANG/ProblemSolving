#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef pair<int,int> pii;
int arr[300002];
 
pii get(int x) {
    int ret = (arr[x] == arr[x - 1]) + (arr[x] == arr[x + 1]);
    if (!arr[x]) return { ret,0 };
    else return { 0,ret };
}
 
void solve(int tc) {
 
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    arr[N + 1] = -1;
 
    int a = 0, b = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] != arr[i - 1]) continue;
        if (!arr[i])  a += 1;
        if (arr[i]) b += 1;
    }
 
    int Q;
    cin >> Q;
    while (Q--) {
        int i, j;
        cin >> i >> j;
        int x = a, y = b;
        x -= get(i).first + get(j).first;
        y -= get(i).second + get(j).second;
        swap(arr[i], arr[j]);
        x += get(i).first + get(j).first;
        y += get(i).second + get(j).second;
        swap(arr[i], arr[j]);
        cout << x << " " << y << endl;
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