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
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;
#define INF 1e18+7;




int N;
ll arr[2000];
vector<ll> h;
ll DP[2000][2000][2];
ll dp(int n, int x, bool dir) {
    if (x == N || x==-1) return INF;
    if (n == N) return 0;
    if (DP[n][x][dir] != -1) return DP[n][x][dir];

    return DP[n][x][dir] = min(abs(arr[n] - h[x]) + dp(n + 1, x, dir), dp(n, x + (dir ? 1 : -1), dir));
    
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        h[i] = arr[i];
        for (int j = 0; j < N; j++) {
            DP[i][j][0] = DP[i][j][1] = -1;
        }
    }
    sort(h.begin(), h.end());

    cout << min(dp(0, 0, 1), dp(0, N-1, 0));


    return 0;
}