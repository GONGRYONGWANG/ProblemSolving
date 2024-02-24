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
    int N, S;
    cin >> N >> S;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int sz = v.size();
        for (int j = 0; j < sz; j++) {
            v.push_back(v[j] + x);
        }
    }
    int ans = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == S) ans += 1;
    }
    cout << ans;
    return 0;
}
