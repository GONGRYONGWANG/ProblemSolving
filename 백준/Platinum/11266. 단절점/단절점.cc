#pragma warning(disable:4996) 
#include<iostream>
#include<iomanip>
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
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;


int N, M;
vector<int> E[10001];
int order[10001];
int cnt;
bool ap[10001];
int dfs(int node, bool root) {
    cnt += 1;
    int ret = order[node] = cnt;
    int childn = 0;
    for (int i = 0; i < E[node].size(); i++) {
        int next = E[node][i];
        if (!order[next]) {
            childn += 1;
            int child_depth = dfs(next, false);
            ret = min(child_depth, ret);
            if (!root && child_depth >= order[node]) ap[node] = true;
        }
        else ret = min(ret, order[next]);
    }
    if (root && childn >= 2) ap[node] = true;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!order[i]) dfs(i, 1);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (ap[i]) ans += 1;
    }
    cout << ans << endl;
    for (int i = 1; i <= N; i++) {
        if (ap[i]) cout << i << " ";
    }


    return 0;
}