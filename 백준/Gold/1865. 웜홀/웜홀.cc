//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
#include<utility>


int N, M, W;
long long dist[501];
bool visited[501];
void TEST() {
    cin >> N>>M>>W;
    vector<pair<int, int>> line[501];
    int S, E, T;
    for (int i = 0; i < M; i++) {
        cin >> S >> E >> T;
        line[S].push_back({ E,T });
        line[E].push_back({ S,T });
    }
    for (int i = 0; i < W; i++) {
        cin >> S >> E >> T;
        line[S].push_back({ E,-T });
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    for (int h = 1; h <= N; h++) {
        if (!visited[h]) {
            dist[h] = 0;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visited[j]) { continue; }
                for (int k = 0; k < line[j].size(); k++) {
                    if (dist[j] != INF && dist[line[j][k].first] > dist[j] + line[j][k].second) {
                        dist[line[j][k].first] = dist[j] + line[j][k].second;
                        if (i == N) { cout << "YES" << endl; return; }
                    }
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (dist[i] != INF) { visited[i] = 1; }
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int TC;
    cin >> TC;
    while (TC--) {
        TEST();
    }
    return 0;
}

