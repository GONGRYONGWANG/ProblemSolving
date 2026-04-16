#pragma warning(disable:4996) 
#include<iostream>
#include<cstdio>
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

ll a[1000001];
ll b[1000001];
ll c[1000001];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    ll N;
    cin >> N;
    ll B, C;
    B = 3;
    C = 2;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    if (B <= C) {
        for (int i = 1; i <= N; i++) {
            ans += a[i] * B;
        }
        cout << ans;
        return 0;
    }
    ans += B * a[1];
    b[1] = a[1];
    c[1] = 0;
    for (int i = 2; i <= N; i++) {
        c[i] = min(min(b[i - 2], c[i - 1]) + b[i - 1], a[i]);
        b[i] = a[i] - c[i];
        ans += C * c[i] + B * b[i];
    }

    cout << ans;
    return 0;
}