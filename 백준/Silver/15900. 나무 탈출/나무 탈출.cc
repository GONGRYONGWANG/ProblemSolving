#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector> 
vector<int> line[500001];
bool visited[500001];
int result;

void DFS(int idx, int depth) {
    visited[idx] = 1;
    for (int i = 0; i < line[idx].size(); i++) {
        if (!visited[line[idx][i]]) {
            DFS(line[idx][i], depth + 1);
        }
    }
    if (line[idx].size() == 1) {
        result += depth%2;
    }
    return;
}

int N;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }
    result = 0;
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
    DFS(1, 0);

    if (result % 2 == 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }

    return 0;
}