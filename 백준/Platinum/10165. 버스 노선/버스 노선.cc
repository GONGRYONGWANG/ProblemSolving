//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e18

bool cmp(vector<ll> a, vector<ll> b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> bus;
    int a, b;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        if (b < a) {
            b += N;
        }
        bus.push_back({ a,b,i });
    }
    sort(bus.begin(), bus.end(),cmp);
    for (int i = 0; i < M; i++) {
        bus.push_back({ bus[i][0] + N,bus[i][1] + N,bus[i][2] });
    }
    vector<bool> ans(M + 1, 1);
    ll e = 0;
    for (int i = 0; i < 2*M; i++) {
        if (bus[i][1] <= e) {
            ans[bus[i][2]] = 0;
        }
        e = max(e,bus[i][1]);
    }
    for (int i = 1; i <= M; i++) {
        if (ans[i]) cout << i << " ";
    }

    return 0;
}
