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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll ans = 1e18;
    vector<ll> ansv;
    for (int i = 0; i < N - 2; i++) {
        int l = i + 1;
        int r = N - 1;
        while (l < r) {
            ll ret = v[i] + v[l] + v[r];
            if (abs(ret) < ans) {
                ans = abs(ret);
                ansv = { v[i],v[l],v[r] };
            }
            if (ret < 0) {
                l += 1;
            }
            else if (ret > 0) {
                r -= 1;
            }
            else {
                cout << ansv[0] << " " << ansv[1] << " " << ansv[2];
                return 0;
            }
        }

    }
    cout << ansv[0] << " " << ansv[1] << " " << ansv[2];
    return 0;

    return 0;
}
