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

int DP[10][26];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N; 
    ull ans = 1;
    ull mod = 1e13;
    for (int i = 1; i <= N; i++) {
        ans *= i;
        while (!(ans % 10)) {
            ans /= 10;
        }
        ans %= mod;
    }
    ans %= 100000;
    cout.width(5);
    cout.fill('0');
    cout << ans;
    return 0;
}