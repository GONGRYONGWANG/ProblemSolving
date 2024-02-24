//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int atr[10000];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    if (N <= M) {
        cout << N; return 0;
    }

    for (int i = 0; i < M; i++) {
        cin >> atr[i];
    }
    long long start, end;
    start = 1;
    end = 30 * N;
    while (start <= end) {
        ll mid = (start + end) / 2;
        ll child = M;
        for (int i = 0; i < M; i++) {
            child += mid / atr[i];
        }
        if (child < N) {
            start = mid + 1;
        }
        else end = mid - 1;
    }

    ll child = M;
    for (int i = 0; i < M; i++) {
        child += end / atr[i];
    }

    for (int i = 0; i < M; i++) {
        if (start % atr[i] == 0) {
            child += 1;
        }
        if (child == N) {
            cout << i + 1; return 0;
        }
    }
    cout << child;
    return 0;
}