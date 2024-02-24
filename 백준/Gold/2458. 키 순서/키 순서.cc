#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N,M;
int compare[501][501];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        compare[a][b] = 1;
        compare[b][a] = -1;
    }
    for (int m = 1; m <= N; m++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (compare[i][m]==1 && compare[m][j]==1) {
                    compare[i][j] = 1;
                    compare[j][i] = -1;
                }
                if (compare[i][m]==-1 && compare[m][j]==-1) {
                    compare[i][j] = -1;
                    compare[j][i] = 1;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        bool state = 1;
        for (int j = 1; j <= N; j++) {
            if (j != i && compare[i][j] == 0) {
                state = 0;
            }
        }
        if (state) { cnt++; }
    }
    cout << cnt;


    return 0;
}
