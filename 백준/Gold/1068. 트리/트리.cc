#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<vector>
vector<int> child[50];
int parent[50];
int cnt;
void nch(int node) {
    for (int i = 0; i < child[node].size(); i++) {
        nch(child[node][i]);
    }
    if (child[node].size() == 0) {
        cnt--;
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x != -1) {
            child[x].push_back(i);
        }
        parent[i] = x;
    }

    cnt = 0;
    for (int i = 0; i < N; i++) {
        if (child[i].size() == 0) {
            cnt++;
        }
    }
    int node;
    cin >> node;
    if (parent[node] == -1) {
        cout << 0; return 0;
    }
    nch(node);
    if (child[parent[node]].size() == 1) {
        cnt++;
    }
    cout << cnt;
    return 0;
}
