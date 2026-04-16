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

ll DP[1000001];



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    DP[0] = 0;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 1; j * i <= 1000000; j++) {
            DP[i * j] += i;
        }
        DP[i] += DP[i - 1];
    }
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << DP[N] << endl;
    }
    return 0;
}
