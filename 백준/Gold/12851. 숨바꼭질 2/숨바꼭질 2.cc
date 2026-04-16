//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;

    int ans = inf;
    int cnt = 0;
    vector<int> visited(100001, 0);
    queue<pii> q;
    q.push({ N,0 }); // position,time
    while (!q.empty() && ans>=q.front().second) {
        int pos = q.front().first;
        int t = q.front().second;
        q.pop();
        if (pos < 0 || pos>100000) {
            continue;
        }
        if (visited[pos] && visited[pos] < t) {
            continue;
        }
        visited[pos] = t;
        if (pos == K) {
            ans = t;
            cnt += 1;
            continue;
        }
        q.push({ pos - 1,t + 1 });
        q.push({ pos + 1,t + 1 });
        q.push({ pos * 2,t + 1 });
    }
    cout << ans << endl << cnt;

    return 0;
}