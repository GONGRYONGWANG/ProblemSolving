//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


vector<int> E[50];

int get(int node) {
    if (E[node].size() == 0) return 0;
    vector<int> child;
    for (int i = 0; i < E[node].size(); i++) {
        child.push_back(get(E[node][i]));
    }
    sort(child.rbegin(), child.rend());
    int ret = 0;
    for (int i = 0; i < child.size(); i++) {
        ret = max(ret, i + 1 + child[i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    int x;
    cin >> x;
    for (int i = 1; i < N; i++) {
        cin >> x;
        E[x].push_back(i);
    }
    cout << get(0);

    return 0;
}