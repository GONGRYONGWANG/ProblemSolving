#pragma warning(disable:4996)
//#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
int N, M;
vector<vector<int>> edge;
vector<vector<int>> reedge;
vector<bool> visited;
stack<int> s;
vector<bool> check;

int Not(int a) {
    if (a < N + 1) {
        return a + N;
    }
    return a - N;
}

void DFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        DFS(edge[node][i]);
    }
    s.push(node);
    return;
}

void reDFS(int node) {
    if (visited[node]) { return; }
    visited[node] = 1;
    for (int i = 0; i < reedge[node].size(); i++) {
        reDFS(reedge[node][i]);
    }
    check[node] = 1;
    return;
}

void Test() {

    edge.clear();
    reedge.clear();
    visited.clear();
    check.clear();
    while (!s.empty()) {
        s.pop();
    }

    edge.resize(2 * N + 1);
    reedge.resize(2 * N + 1);
    visited.resize(2 * N + 1);
    check.resize(2 * N + 1);

    for (int i = 1; i <= 2 * N; i++) {
        visited[i] = 0;
    }

    int x, y;
    char cx, cy;
    for (int i = 0; i < M; i++) {
        cin >> cx >> x >> cy>> y;
        if (cx == '-') { x = -x; }
        if (cy == '-') { y = -y; }
        if (x < 0) { x = abs(x) + N; }
        if (y < 0) { y = abs(y) + N; }
        edge[Not(x)].push_back(y);
        reedge[y].push_back(Not(x));
        edge[Not(y)].push_back(x);
        reedge[x].push_back(Not(y));
    }

    for (int i = 1; i <= 2 * N; i++) {
        DFS(i);
    }

    for (int i = 1; i <= 2 * N; i++) {
        visited[i] = 0;
    }

    while (!s.empty()) {
        if (!visited[s.top()]) {
            for (int i = 1; i <= 2 * N; i++) {
                check[i] = 0;
            }
            reDFS(s.top());
            for (int i = 1; i <= N; i++) {
                if (check[i] && check[i + N]) {
                    cout << 0 << endl; return;
                }
            }
        }
        s.pop();
    }
    cout << 1 << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    while (cin >> N && cin >> M) {
        Test();
    }
    return 0;
}

