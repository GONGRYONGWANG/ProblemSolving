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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

vector<ll> idx;
ll find(ll x) {
    ll y = *(upper_bound(idx.begin(), idx.end(), x)- 1);
    if (x == y) {
        return x;
    }
    return find(x - y);
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll N;
    cin >> N;
    idx.push_back(1);
    idx.push_back(2);
    while (idx.back() <= N) {
        idx.push_back(*(idx.end()-2)+*(idx.end()-1));
    }
    if (N == *(upper_bound(idx.begin(), idx.end(), N) - 1)) {
        cout << -1; 
        return 0;
    }
    cout << find(N);
    return 0;
}