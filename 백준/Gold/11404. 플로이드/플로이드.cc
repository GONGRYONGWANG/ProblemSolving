#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N, M;
#include<vector>
#include<utility>
#include<algorithm>
int line[101][101];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N >> M;
    int a, b, c;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            line[i][j] = INF;
        }
    }
    for (int i = 0; i< M; i++) {
        cin >> a >> b >> c;
        line[a][b] = min(line[a][b],c);
    }
    for (int i = 1; i <= N; i++) {
        line[i][i] = 0;
    }
    for (int m = 1; m <= N; m++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (line[i][m] + line[m][j] < line[i][j]) {
                    line[i][j] = line[i][m]+line[m][j];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (line[i][j] == INF) {
                cout << 0 << " ";
            }
            else {
                cout << line[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
