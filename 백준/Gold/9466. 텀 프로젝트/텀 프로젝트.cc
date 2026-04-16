#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int pick[100001];
bool visited[100001];
bool fin[100001];
int result;
void DFS(int idx) {
    visited[idx] = 1;
    int nextnode = pick[idx];
    if (!visited[nextnode]) {
        DFS(nextnode);
    }
    else if (!fin[nextnode]) {
        for (int i = nextnode; i != idx; i = pick[i]) {
            result++;
        }
        result++;
    }
    fin[idx] = 1;
}


int n;
void TEST() {
    result = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pick[i];
        visited[i] = 0;
        fin[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    cout << n - result << endl;

}



int T;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        TEST();
    }

    return 0;
}