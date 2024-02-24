#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18
#include<vector>
#include<stack>
vector<vector<int>> edge;
vector<vector<int>> reedge;
vector<bool> visited;
vector<int> check;
stack<int> s;
int N, M, K;
void DFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        DFS(edge[node][i]);
    }
    s.push(node);
    return;
}
int cnt;
void reDFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < reedge[node].size(); i++) {
        reDFS(reedge[node][i]);
    }
    check[node] = cnt;
    return;
}
int Not(int x) {
    if (x <= N + M) {
        return x + N + M;
    }
    else return x - N - M;
}

int MAIN() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M>>K;
    edge.clear();
    reedge.clear();
    visited.clear();
    check.clear();
    edge.resize(2 * (N + M) + 1);
    reedge.resize(2 * (N + M) + 1);
    visited.resize(2 * (N + M) + 1);
    check.resize(2 * (N + M) + 1);
    int a, b, c, d;
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c >> d;
        b += N;
        d += N;
        if (a == c && c == d) {
            continue;
        }
        if (a > c) {
            b = Not(b);
            d = Not(d);
        }
        if (b > d) {
            a = Not(a);
            c = Not(c);
        }
        if (a != c && b!=d) {
            edge[Not(a)].push_back(c);
            edge[Not(a)].push_back(b);
            edge[Not(c)].push_back(a);
            edge[Not(c)].push_back(d);
            edge[Not(b)].push_back(d);
            edge[Not(b)].push_back(a);
            edge[Not(d)].push_back(b);
            edge[Not(d)].push_back(c);
            reedge[c].push_back(Not(a));
            reedge[b].push_back(Not(a));
            reedge[a].push_back(Not(c));
            reedge[d].push_back(Not(c));
            reedge[d].push_back(Not(b));
            reedge[a].push_back(Not(b));
            reedge[b].push_back(Not(d));
            reedge[c].push_back(Not(d));
        }
        if (a == c) {
            edge[Not(a)].push_back(a);
            reedge[a].push_back(Not(a));
        }
        if (b == d) {
            edge[Not(b)].push_back(b);
            reedge[b].push_back(Not(b));
        }
    }
    for (int i = 1; i <= 2 * (N + M); i++) {
        visited[i] = 0;
    }

    for (int i = 1; i <= 2 * (N + M); i++) {
        DFS(i);
    }

    for (int i = 1; i <= 2 * (N + M); i++) {
        visited[i] = 0;
    }
    cnt = 0;
    while (!s.empty()) {
        if (!visited[s.top()]) {
            cnt++;
            reDFS(s.top());
        }
        s.pop();
    }
    for (int i = 1; i <= (N + M); i++) {
        if (check[i] == check[i + N + M]) {
            cout << "No"<<endl; return 0;
        }
    }
    cout << "Yes"<<endl;
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        MAIN();
    }
    return 0;
}

