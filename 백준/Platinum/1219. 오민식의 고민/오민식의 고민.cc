//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18

#include<vector>
#include<utility>
vector<pair<int, int>> line[100];
vector<int> lines[100];
int profit[100];
long long dist[100];
bool cycle[100];
int N,M;
int S, E;

#include<queue>
void BFS() {
    queue<int> Q;
    for (int i = 0; i <= N; i++) {
        if (cycle[i]) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (int i = 0; i < line[node].size(); i++) {
            if (!cycle[line[node][i].first]) {
                cycle[line[node][i].first] = 1;
                Q.push(line[node][i].first);
            }
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> S>>E>>M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        lines[i] = { a,b,c };
    }
    for (int i = 0; i < N; i++) {
        cin >> profit[i];
    }
    for (int i = 0; i < M; i++) {
        a = lines[i][0];
        b = lines[i][1];
        c = lines[i][2];
        line[a].push_back({ b,profit[b]-c });
    }
    for (int i = 0; i < N; i++) {
        dist[i] = -INF;
    }


    dist[S] = profit[S];
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < line[j].size(); k++) {
                if (dist[j] != -INF && dist[line[j][k].first] < dist[j] + line[j][k].second) {
                    dist[line[j][k].first] = dist[j] + line[j][k].second;
                    if (i == N) {
                        cycle[line[j][k].first] = 1;
                    }
                }
            }
        }
    }

    BFS();


    if (cycle[E]) { cout << "Gee"; return 0; }
    if (dist[E] == -INF) { cout << "gg"; return 0; }
    cout << dist[E];


    return 0;
}

