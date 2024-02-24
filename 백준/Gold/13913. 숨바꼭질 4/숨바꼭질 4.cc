//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<iostream>
using namespace std;
#define endl "\n"

bool visited[200001];
int parent[200001];
#include<vector>
#include<queue>
queue<int> invest;
int N, K;
int cnt;
void DFS() {
    invest.push(N);
    visited[N] = 1;
    cnt = 0;
    int s;
    while (!visited[K]) {
        s = invest.size();
        for (int i = 0; i < s; i++) {
            int x = invest.front();
            invest.pop();
            if (x<=100000 && !visited[x * 2]) { invest.push(x * 2); visited[x * 2] = 1; parent[x * 2] = x; }
            if (x > 0 && !visited[x - 1]) { invest.push(x - 1); visited[x - 1] = 1; parent[x - 1] = x; }
            if (x < 100000 && !visited[x + 1]) { invest.push(x + 1); visited[x + 1] = 1; parent[x + 1] = x; }
        }
        cnt++;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> K;
    DFS();
    cout << cnt<<endl;
    vector<int> ans;
    while (K != N) {
        ans.push_back(K);
        K = parent[K];
    }
    ans.push_back(N);
    for (int i = cnt; i >=0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}

