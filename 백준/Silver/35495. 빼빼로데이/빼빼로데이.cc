#include<bits/stdc++.h>
using namespace std;
 
int D[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30, 31 };
 
bool get(int t, int a, int b, int c) {
    int cnt = 0;
    while (a) {
        cnt += (a % 10 == 1);
        a /= 10;
    }
    while (b) {
        cnt += (b % 10 == 1);
        b /= 10;
    }
    while (c) {
        cnt += (c % 10 == 1);
        c /= 10;
    }
    return cnt >= t;
}
 
void solve(int tc) {
    
    int T, A, B, C;
    cin >> T >> A >> B >> C;
 
    int a = 2023, b = 1, c = 1;
    int ret = get(T, A, B, C);
    while (a != A || b != B || c != C) {
        if (b == 13) {
            b = 1; a += 1;
            continue;
        }
 
        if (c > D[b]) {
            if (b == 2 && (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)) && c == 29);
            else {
                c = 1;
                b += 1;
                continue;
            }
        }
 
        ret += get(T, a, b, c);
        c += 1;
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
