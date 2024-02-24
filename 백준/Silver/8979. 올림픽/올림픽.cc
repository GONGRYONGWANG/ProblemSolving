//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    
    int N, K;
    vector<vector<int>> con;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        vector<int> v(5);
        cin >> v[4];
        for (int j = 0; j < 3; j++) {
            cin >> v[j];
        }
        v[3] = 0;
        con.push_back(v);
        if (v[4] == K) {
            v[4] = N + 1;
            v[3] = 1;
            con.push_back(v);
        }
    }
    sort(con.rbegin(), con.rend());
    int idx = 0;
    while (con[idx][4] != N + 1) {
        idx++;
    }
    cout << idx + 1;


    return 0;
}