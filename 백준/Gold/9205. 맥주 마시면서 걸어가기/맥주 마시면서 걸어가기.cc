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
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

vector<int> E[102];
pii V[102];
bool visited[102];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N + 2; i++) {
            E[i].clear();
        }
        for (int i = 0; i < N+2; i++) {
            int x, y;
            cin >> x >> y;
            V[i] = { x,y };
            for (int j = 0; j < i; j++) {
                int dx = abs(V[i].first - V[j].first);
                int dy = abs(V[i].second - V[j].second);
                if (dx + dy > 1000) continue;
                E[i].push_back(j);
                E[j].push_back(i);
            }
        }
        fill(visited, visited + N + 2, false);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == N + 1) break;
            for (int i = 0; i < E[node].size(); i++) {
                if (visited[E[node][i]]) continue;
                visited[E[node][i]] = 1;
                q.push(E[node][i]);
            }
        }
        if (visited[N + 1]) cout << "happy";
        else cout << "sad";
        cout << endl;
    }
    
    return 0;
}

