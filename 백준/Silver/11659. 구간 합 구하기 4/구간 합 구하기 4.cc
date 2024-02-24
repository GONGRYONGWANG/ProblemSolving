#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


int N,M;
int seq[100001];
int from1[100001];
int fromN[100002];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int y = 0;
    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
        y += seq[i];
    }
    int x = 0;
    for (int i = 1; i <= N; i++) {
        x += seq[i];
        from1[i] = x;
        fromN[i] = y;
        y -= seq[i];
    }
    from1[0] = 0;
    fromN[N + 1] = 0;
    int a,b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << from1[N] - from1[a-1] - fromN[b + 1] << endl;
    }

    return 0;
}
