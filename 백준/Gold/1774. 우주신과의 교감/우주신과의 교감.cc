//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<cmath>
int N, M;
int x[1001];
int y[1001];
bool visited[1001];
double dist[1001][1001];
#include<queue>
#include<utility>
#include<vector>
struct cmp {
    bool operator()(pair<int, double> a, pair<int, double> b){
        return a.second > b.second;
    }
};
priority_queue<pair<int,double>,vector<pair<int,double>>,cmp> Q;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
        }
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        dist[a][b] = 0;
        dist[b][a] = 0;
    }
    Q.push({ 1,0 });
    double ans = 0;
    int visit = 0;
    while (visit != N) {
        int node = Q.top().first;
        if (visited[node]) { Q.pop(); continue; }
        ans += Q.top().second;
        visit++;
        visited[node] = 1;
        Q.pop();
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                Q.push({ i, dist[node][i] });
            }
        }
    }
    printf("%.2f", ans);
    return 0;
}

