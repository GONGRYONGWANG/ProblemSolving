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
#include<complex> // complex number
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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

pii parent[1000][1000];

pii find(pii x) {
    if (parent[x.first][x.second] == x) return x;
    return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void mer(pii a, pii b) {
    if (find(a) == find(b)) return;
    parent[find(b).first][find(b).second] = find(a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <M ; j++) {
            parent[i][j] = { i,j };
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            if (x == 'D') {
                mer({ i,j }, { i + 1,j });
            }
            else if (x == 'U') {
                mer({ i - 1,j }, { i,j });
            }
            else if (x == 'R') {
                mer({ i,j }, { i,j + 1 });
            }
            else {
                mer({ i,j - 1 }, { i,j });
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (find({ i,j }) == make_pair(i,j)) ans += 1;
        }
    }
    cout << ans;
    return 0;
}