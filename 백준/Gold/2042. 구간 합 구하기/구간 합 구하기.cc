//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define INF (1<<32)
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;
#define fi first
#define se second

ll arr[1000001];
ll tree[1000001];
ll N;

ll sum(int idx) {
    ll rt = 0;
    while (idx > 0) {
        rt += tree[idx];
        idx &= (idx - 1);
    }
    return rt;
}

void update(int idx, ll val) {
    while (idx <= N) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
    return;
}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll M, K;
    ll a, b, c;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c - arr[b]);
            arr[b] = c;
        }
        else {
            cout << sum(c) - sum(b-1)<<endl;
        }
    }
    return 0;
}