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


int mx[250][250];
int mn[250][250];

int board[250][250];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, B, K;
    cin >> N >> B >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - B; j++) {
            mx[i][j] = 0;
            mn[i][j] = inf;
            for (int k = j; k < j + B; k++) {
                mx[i][j] = max(mx[i][j], board[i][k]);
                mn[i][j] = min(mn[i][j], board[i][k]);
            }
        }
    }
    while (K--) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        int _mx = 0;
        int _mn = inf;
        for (int i = a; i < a + B; i++) {
            _mx = max(_mx, mx[i][b]);
            _mn = min(_mn, mn[i][b]);
        }
        cout << _mx - _mn << endl;
    }

    return 0;
}