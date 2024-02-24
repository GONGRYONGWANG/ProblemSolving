//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
vector<int> precon[32001];
int preconnum[32001];
int visited[32001];

int N, M;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        preconnum[b] += 1;
        precon[a].push_back(b);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            if (preconnum[j] == 0 && !visited[j]) {
                cout << j << " ";
                visited[j] = 1;
                for (int k = 0; k < precon[j].size();k++) {
                    preconnum[precon[j][k]] -= 1;
                }
                break;
            }
        }
    }
    return 0;
}

