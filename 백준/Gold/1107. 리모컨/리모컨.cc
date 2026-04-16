//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

bool broke[10];

bool can(int x) {
    if (x < 0) return 0;
    if (x < 10) return !broke[x];
    int d = 10000000;
    while (d > x) {
        d /= 10;
    }
    while (d != 0) {
        if (broke[x / d]) return 0;
        x %= d;
        d /= 10;
    }
    return 1;
}

int leng(int x) {
    if (x == 0) return 1;
    int ret = 0;
    while (x != 0) {
        x /= 10;
        ret += 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    if (M == 10) {
        cout<< abs(N - 100);
        return 0;
    }
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        broke[x] = 1;
    }
    int f = N;
    int b = N;
    while (!can(f) && !can(b)) {
        f--; b++;
    }
    int ans = abs(N - 100);
    if (can(f)) {
        ans = min(ans, N - f + leng(f));
    }
    if (can(b)) {
        ans = min(ans, b - N + leng(b));
    }
    cout << ans;
    return 0;
}