//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector> 
#include<utility>
vector<pair<int,int>> bus[501];
long long dist[501];

int N,M;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N>>M;
    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        bus[A].push_back({ B,C });
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    bool cycle = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < bus[j].size(); k++) {
                if (dist[j] != INF && dist[bus[j][k].first] > bus[j][k].second + dist[j]) {
                    dist[bus[j][k].first] = bus[j][k].second + dist[j];
                    if (i == N) { cycle = 1; }
                }
            }
        }
    }
    if (cycle) { cout << "-1"; return 0; }
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) { cout << -1 << endl; }
            else { cout << dist[i] << endl; }
        }
    }
    return 0;
}

