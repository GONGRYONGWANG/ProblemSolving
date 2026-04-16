#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N;
bool edge[100][100];


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> edge[i][j];
        }
    }
    for (int m = 0; m < N; m++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (edge[i][m] && edge[m][j]) {
                    edge[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
