//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9
int N, K;
int parent[1001];
bool visited[1001];
bool completed[1001];
int group[1001][2];
bool loop[1001];
#include<vector>
vector<int> gr;
void DFS(int node) {
    if (completed[node]) { return; }
    if (visited[node]) {
        completed[node]=1;
        loop[node] = 1;
        int idx = parent[node];
        group[node][0]++;
        while (idx != node) {
            group[node][0]++;
            loop[idx] = 1;
            idx = parent[idx];
        }
        parent[node] = node;
        gr.push_back(node);
    }
    visited[node] = 1;
    DFS(parent[node]);
    parent[node] = parent[parent[node]];
    if (!loop[node]) {
        group[parent[node]][1]++;
    }
    completed[node] = 1;
    visited[node] = 0;
    return;
}

bool DP[2001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
    }
    for (int i = 1; i <= N; i++) {
        if (!completed[i]) {
            DFS(i);
        }
    }

    DP[0] = 1;

    for (int i = 0; i < gr.size(); i++) {
        for (int j = K; j >= 0; j--) {
            if (DP[j]) {
                for (int m = 0; m <= group[gr[i]][1]; m++) {
                    DP[j + group[gr[i]][0] + m] = 1;
                }
            }
        }
    }

    for (int i = K; i >= 0; i--) {
        if (DP[i]){
            cout << i; return 0;
        }
    }


    return 0;
}

