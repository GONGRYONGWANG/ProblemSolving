//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9



int N, M;
bool visited[10001][200];
bool sr[10001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int x,s,n;
    for (int i = 0; i < M; i++) {
        cin >> x;
        sr[x] = 1;
    }
    queue<vector<int>> q;
    q.push({ 2,1,1 });
    while (!q.empty()) {
        x = q.front()[0]; s = q.front()[1]; n = q.front()[2];
        if (x == N) { cout << n; return 0; }
        q.pop();
        if (x > N || s==0) continue;
        if (visited[x][s]) continue;
        visited[x][s] = 1;
        if (sr[x]) continue;
        q.push({ x + s + 1,s + 1,n + 1 });
        q.push({ x + s,s,n + 1 });
        q.push({ x + s - 1,s - 1,n + 1 });
    }
    cout << -1;
    return 0;
}