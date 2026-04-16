#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N;
char picture[100][100];
bool visited[100][100];
bool visited2[100][100];
void check(int x, int y) {
    visited[x][y] = 1;
    char c = picture[x][y];
    if (x != 0 && !visited[x - 1][y] && picture[x - 1][y] == c) {
        visited[x - 1][y] = 1;
        check(x - 1, y);
    }
    if (x != N-1 && !visited[x + 1][y] && picture[x + 1][y] == c) {
        visited[x + 1][y] = 1;
        check(x + 1, y);
    }
    if (y != 0 && !visited[x][y - 1] && picture[x][y - 1] == c) {
        visited[x][y - 1] = 1;
        check(x, y - 1);
    }
    if (y != N-1 && !visited[x][y + 1] && picture[x][y + 1] == c) {
        visited[x][y + 1] = 1;
        check(x, y + 1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> picture[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                check(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";

    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (picture[i][j] == 'R') {
                picture[i][j] = 'G';
            }
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                check(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
