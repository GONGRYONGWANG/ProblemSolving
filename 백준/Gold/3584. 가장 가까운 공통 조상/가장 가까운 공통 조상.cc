//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e18
int N;
int parent[10001];

void Test() {
    cin >> N;
    int u, v;
    for (int i = 0; i < N; i++) {
        parent[i] = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        parent[v] = u;
    }

    cin >> u >> v;

    while (1) {
        int cv = v;
        while (cv != 0) {
            if (cv == u) {
                cout << u << endl; return;
            }
            cv = parent[cv];
        }
        u = parent[u];
    }

    return;
}




int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        Test();
    }

    
    return 0;
}

