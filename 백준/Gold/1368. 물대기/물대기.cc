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
//const double pi = 3.14159265358979323846;


vector<pii> E[301];
bool visited[301];

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int w;
        cin >> w;
        E[0].push_back({ i,w });
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int p;
            cin >> p;
            if (i == j) continue;
            E[i].push_back({ j,p });
        }
    }
    int ans = 0;
    pq<pii, vector<pii>, cmp> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        int node = q.top().first;
        if (visited[node]) {
            q.pop();
            continue;
        }
        visited[node] = 1;
        ans += q.top().second;
        q.pop();
        for (int i = 0; i < E[node].size(); i++) {
            int next = E[node][i].first;
            if (visited[next]) continue;
            q.push(E[node][i]);
        }
    }
    cout << ans;
    return 0;
}