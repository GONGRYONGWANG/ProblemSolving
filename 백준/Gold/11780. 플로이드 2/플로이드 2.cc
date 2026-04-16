//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18

#include<algorithm>
#include<vector>
int N, M;
long long dist[101][101];
vector<long long> route[101][101];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }
    
    long long a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        route[a][b] = { a, b };
    }
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
        route[i][i] = { i };
    }

    for (int m = 1; m <= N; m++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][m] + dist[m][j] < dist[i][j]) {
                    dist[i][j] = dist[i][m] + dist[m][j];
                    route[i][j].clear();
                    for (int k = 0; k < route[i][m].size(); k++) {
                        route[i][j].push_back(route[i][m][k]);
                    }
                    for (int k = 1; k < route[m][j].size(); k++) {
                        route[i][j].push_back(route[m][j][k]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) { cout << 0 << " "; }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) { cout << 0 << endl; continue; }
            if (dist[i][j] == INF) { cout << 0 << endl; continue; }
            cout << route[i][j].size()<<" ";
            for (int k = 0; k < route[i][j].size(); k++) {
                cout << route[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

