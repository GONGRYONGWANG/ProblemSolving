#pragma warning(disable:4996) 
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
#define pb push_back
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

bool prime[2000];
int N;

vector<int> E[26];
int assign[26];
bool done[51];

bool dfs(int x) {
    for (int i = 0; i < E[x].size(); i++) {
        int target = E[x][i];
        if (done[target]) continue;
        done[target] = 1;
        if (assign[target] == 0 || dfs(assign[target])) {
            assign[target] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    fill(prime, prime + 2000, true);
    for (int i = 2; i < 2000; i++) {
        if (!prime[i]) continue;
        for (int j = i * 2; j < 2000; j += i) {
            prime[j] = false;
        }
    }

    cin >> N;
    N /= 2;
    vector<int> g1 = { 0 };
    vector<int> g2 = { 0 };
    int x;
    cin >> x;
    g1.push_back(x);
    for (int i = 1; i < 2 * N; i++) {
        cin >> x;
        if ((x + g1[1]) % 2) g2.push_back(x);
        else g1.push_back(x);
    }

    if (g1.size() != N + 1) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (prime[g1[i] + g2[j]]) E[i].push_back(j);
        }
    }

    vector<int> ans;
    for (int i = 0; i < E[1].size(); i++) {
        fill(assign, assign + N + 1, 0);
        bool x = 1;
        for (int j = 2; j <= N; j++) {
            fill(done, done + N + 1, false);
            done[E[1][i]] = 1;
            if (!dfs(j)) {
                x = 0;
                break;
            }
        }
        if (x) ans.push_back(g2[E[1][i]]);
    }
    if (ans.empty()) {
        cout << -1; 
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}