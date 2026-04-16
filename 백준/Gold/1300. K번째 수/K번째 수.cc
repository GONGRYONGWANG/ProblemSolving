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


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int s, e;
    s = 0;
    e = K;
    while (1) {
        int mid = (s + e) / 2;
        int ret1 = 0;
        int ret2 = 0;
        for (int i = 1; i <= N; i++) {
            ret1 += min(mid / i,N);
            ret2 += min((mid - 1) / i,N);
        }
        if (K > ret1) {
            s = mid + 1;
        }
        else if (K > ret2) {
            cout << mid;
            return 0;
        }
        else e = mid - 1;
    }
    return 0;
}