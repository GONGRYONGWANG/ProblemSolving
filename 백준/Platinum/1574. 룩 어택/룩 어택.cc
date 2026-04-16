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



bool space[301][301];
unordered_map<int, vector<int>> E;
unordered_map<int, int> assign;
unordered_map<int, bool > done;
int R, C, N;

bool dfs(int x) {
    for (int i = 0; i < E[x].size(); i++) {
        int target = E[x][i];
        if (done[target]) continue;
        done[target] = 1;
        if (assign[target]==0 || dfs(assign[target])) {
            assign[target] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> R >> C >> N;
    if (N == 0) {
        cout << min(R, C);
        return 0;
    }
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        space[a][b] = 1;
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (space[i][j]) continue;
            E[i].push_back(j);
        }
    }

    int ans = 0;
    for (int i = 1; i <= R; i++) {
        done.clear();
        if (dfs(i)) ans += 1;
    }

    cout << ans;

    return 0;
}