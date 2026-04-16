//#pragma warning(disable:4996) 
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<utility>
#include<string>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


vector<int> parent;
int find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    parent.resize(N + 2);
    for (int i = 1; i <= N; i++) {
        parent[i] = i + 1;
    }
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        parent[x] = x;
    }
    parent[0] = 0;
    parent[N + 1] = N + 1;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        cout << find(x+1)<<endl;
        parent[find(x+1)] = find(find(x+1) + 1);
    }

    return 0;
}