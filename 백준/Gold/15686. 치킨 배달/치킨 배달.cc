//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define INF (1<<32)
#define inf 1e9
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;
#define fi first
#define se second

int city[52][52];
int cd[52][52];
vector<pii> ck;
vector<pii> home;
int N, M;

int get(int k, int idx) {
    int rt = inf;
    if (ck.size() -idx < k) return rt;
    if (ck.size() - idx == k) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (city[i][j] == 2) { cd[i][j] = 0; }
                else cd[i][j] = inf;
                cd[i][j] = min(min(cd[i - 1][j], cd[i][j - 1]) + 1, cd[i][j]);
            }
        }
        for (int i = N; i >= 1; i--) {
            for (int j = N; j >= 1; j--) {
                cd[i][j] = min(min(cd[i + 1][j], cd[i][j + 1]) + 1, cd[i][j]);
            }
        }
        rt = 0;
        for (int i = 0; i < home.size(); i++) {
            rt += cd[home[i].first][home[i].second];
        }
        return rt;
    }
    city[ck[idx].first][ck[idx].second] = 0;
    rt = min(get(k, idx + 1),rt);
    city[ck[idx].first][ck[idx].second] = 2;
    rt = min(get(k-1, idx + 1),rt);
    return rt;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cd[i][0] = cd[i][N + 1] = inf;
        for (int j = 1; j <= N; j++) {
            cd[0][j] = cd[N + 1][j] = inf;
            cin >> city[i][j];
            if (city[i][j] == 1) home.push_back({ i,j });
            else if (city[i][j] == 2)ck.push_back({ i,j });
        }
    }
    cout<< get(M, 0);
    return 0;
}