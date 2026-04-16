//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int M, N;
    cin >> M >> N;
    vector<ull> v;
    ull tc = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        tc += x;
    }
    sort(v.begin(), v.end());
    ull ans = 0;
    for (int i = 0; i < N; i++) {
        ull thrs = (tc - M) / (N - i);
        tc -= v[i];
        if(v[i]>=thrs) {
            M -= v[i] - thrs;
            v[i] = thrs;
        }
        ans += v[i] * v[i];
    }
    cout << ans;
    return 0;
}