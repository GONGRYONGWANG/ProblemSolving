#pragma warning(disable:4996) 
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
#define pb push_back
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        ll ans = 0;
        ll N;
        cin >> N;
        ll s, t;
        cin >> s >> t;
        while (N != 1) {
            if (N % 2) {
                ans += s;
                N -= 1;
                continue;
            }
            if (N/2 > (ll)1e9 || t < s * (N / 2)) {
                ans += t;
                N /= 2;
                continue;
            }
            ans += (N - 1) * s;
            N = 1;
        }
        ans += s;
        cout << ans << endl;
    }

    return 0;
}