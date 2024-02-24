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
const double pi = 3.14159265358979323846;

ll DP[161051][5][5];
ll dp(int biz, int p, int pp) {
    if (biz == 0) return 1;
    if (DP[biz][p][pp]!=-1) return DP[biz][p][pp];
    vector<int> b(5);
    int _biz = biz;
    for (int i = 0; i < 5; i++) {
        b[i] = _biz % 11;
        _biz /= 11;
    }
    ll ret = 0;
    for (int i = 0; i < 5; i++) {
        if (p == i || pp == i || b[i] == 0 ) continue;
        ret += dp(biz - (int)pow(11, i), i, p);
    }
    return DP[biz][p][pp] = ret;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < 161051; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                DP[i][j][k] = -1;
            }
        }
    }
    int biz = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        biz += (int)pow(11, i) * x;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp(biz - (int)pow(11, i), i, i);
    }
    cout << ans;
    return 0;
}