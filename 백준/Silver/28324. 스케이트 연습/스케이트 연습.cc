//#pragma warning(disable:4996) 
//#include<bits/stdc++.h>
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
int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    stack<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    int speed = 0;
    ll ans = 0;
    while (!s.empty()) {
        speed = min(speed + 1, s.top());
        ans += speed;
        s.pop();
    }
    cout << ans;


    return 0;
}