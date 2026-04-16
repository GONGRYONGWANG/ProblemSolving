#include<iostream>
#include<iomanip>
#include<cstdio>
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
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const int inf = 1e9;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
//const double pi = 3.14159265358979323846;



int parent[30001];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    parent[find(a)] = find(b);
}

int visited[30001];
int DP[3001];
int c[30001];
int candy[30001];
int sz[30001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        parent[i] = i;
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    for (int i = 1; i <= N; i++) {
        sz[find(i)] += 1;
        candy[find(i)] += c[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[find(i)]) continue;
        visited[find(i)] = true;
        for (int j = K-sz[find(i)]-1; j>=0; j--) {
            DP[j + sz[find(i)]] = max(DP[j + sz[find(i)]], DP[j] + candy[find(i)]);
            ans = max(ans, DP[j + sz[find(i)]]);
        }
    }
    cout << ans;

    return 0;
}