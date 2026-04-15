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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, L;
    cin >> N >> L;
    while (L <= 100) {
        if (L % 2) {
            if (N / L - L / 2 < 0) break;
            if (N % L == 0) {
                for (int i = -L / 2; i <= L / 2; i++) {
                    cout << N/L + i<<" ";
                }
                return 0;
            }
        }
        else {
            if (N / L - L / 2 + 1 < 0) break;
            if (N % L == L / 2) {
                for (int i = -L / 2 + 1; i <= L / 2; i++) {
                    cout << N / L + i << " ";
                }
                return 0;
            }
        }
        L++;
    }
    cout << -1;

    return 0;
}
