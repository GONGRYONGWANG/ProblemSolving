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
    int N;
    cin >> N;

    int ans = 0;
    ll l = 1;
    ll r = N;
    while (l <= r) {
        ll ret = (l + r) * (r - l + 1) / 2;
        if (ret > N) r -= 1;
        else if (ret == N) {
            ans += 1;
            l += 2;
            r += 1;
        }
        else {
            l += 1;
            r += 1;
        }
    }
    cout << ans;


    return 0;
}