#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


int map[30][30];
int nmap[30][30];
bool visited[30][30];
int N, M;


void DFS(int x, int y, int a, int b) {
    if (visited[x][y]) {
        return;
    }
    visited[x][y] = 1;
    if (map[x][y] != a) { return; }
    map[x][y] = b;
    if (x != 0) {
        DFS(x - 1, y, a, b);
    }
    if (y != 0) {
        DFS(x, y - 1, a, b);
    }
    if (x != N - 1) {
        DFS(x + 1, y, a, b);
    }
    if (y != M - 1) {
        DFS(x, y + 1, a, b);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> nmap[i][j];
        }
    }
    bool state = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != nmap[i][j]) {
                state = 1;
                DFS(i, j, map[i][j], nmap[i][j]);
                break;
            }
        }
        if (state) {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != nmap[i][j]) {
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES"; 
    return 0;
}

