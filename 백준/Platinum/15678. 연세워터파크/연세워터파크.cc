#pragma warning(disable:4996) 
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<utility>
#include<string>
#include<set>
#include<unordered_set>
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
#define inf 1e9



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, D;
    cin >> N >> D;

    ll ans = -inf;
    deque<pll> dq;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        ll ret = x;
        while (!dq.empty() && dq.front().first < i - D) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            ret = max(ret, dq.front().second + x);
        }
        while (!dq.empty() && dq.back().second < ret) {
            dq.pop_back();
        }
        dq.push_back({ i,ret });
        ans = max(ans, ret);
    }
    cout << ans;
    return 0;
}