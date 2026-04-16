//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e18

int N, M;
int val[100001][11];
int sat[100001][11];

int get(int day, int des) {
    if (sat[day][des]!=-1) return sat[day][des];
    int rt = 0;
    for (int i = 1; i <= M; i++) {
        if (i == des) {
            rt = max(rt, get(day - 1,i) + val[day][des] / 2);
        }
        else {
            rt = max(rt, get(day - 1, i) + val[day][des]);
        }
    }
    return sat[day][des] = rt;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> val[j][i];
            sat[j][i] = -1;
        }
    }
    for (int i = 1; i <= M; i++) {
        sat[1][i] = val[1][i];
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        ans = max(ans, get(N, i));
    }
    cout << ans;
    return 0;
}
