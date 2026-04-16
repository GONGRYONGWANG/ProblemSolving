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

int N;
vector<int> E[101];
int assign[51];
bool done[51];
bool dfs(int x) {
    for (int i = 0; i < E[x].size(); i++) {
        int target = E[x][i];
        if (done[target]) continue;
        done[target] = 1;
        if (assign[target] == 0 || dfs(assign[target])) {
            assign[target] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N;
    vector<vector<int>> v = { {0,0,0} };
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ a,b,c });
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <=N; j++) {
            if (v[i][0] == v[j][0] && v[i][1] == v[j][1] && v[i][2] == v[j][2]) {
                if (i <= j) continue;
            }
            if (v[i][0] >= v[j][0] && v[i][1] >= v[j][1] && v[i][2] >= v[j][2]) {
                E[i].push_back(j);
                E[i + N].push_back(j);
            }
        }
    }


    int ans = 0;

    for (int i = 1; i <= 2 * N; i++) {
        fill(done, done + N + 1, false);
        if (dfs(i)) ans += 1;
    }
    cout << N - ans;

    return 0;
}