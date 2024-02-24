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
const int inf = 1e9;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

vector<pii> E[1001];
bool visited[1001];

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({ b,c });
        E[b].push_back({ a,c });
    }
    int ans = 0;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        int node = q.top().first;
        int cost = q.top().second;
        q.pop();
        if (visited[node]) continue;
        visited[node] = 1;
        ans += cost;
        for (int i = 0; i < E[node].size(); i++) {
            pii next = E[node][i];
            if (visited[next.first]) continue;
            q.push(next);
        }
    }
    cout << ans;



    return 0;
}