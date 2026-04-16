#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int n, k;
int previous[401][401];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        previous[a][b] = 1;
        previous[b][a] = -1;
    }
    for (int m = 1; m <= n; m++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (previous[i][m]!=0&&previous[i][m] == previous[m][j]) {
                    previous[i][j] = previous[i][m];
                    previous[j][i] = -previous[i][m];
                }
            }
        }
    }
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        cout << -previous[a][b] << endl;
    }



    return 0;
}
