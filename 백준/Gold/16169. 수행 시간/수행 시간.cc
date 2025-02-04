// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
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
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<int> E[101];
int cnt[101];
int lv[101];
int t[101];
int dist[101];

void solve(int tc) {
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        cin >> lv[i] >> t[i];
        if (lv[i] == 1) q.push(i);
        for (int j = 1; j < i; j++) {
            if (lv[j] == lv[i] - 1) {
                E[j].push_back(i);
                cnt[i] += 1;
            }
            if (lv[j] == lv[i] + 1) {
                E[i].push_back(j);
                cnt[j] += 1;
            }
        }
    }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            dist[nx] = max(dist[nx], dist[x] + t[x] + (x - nx) * (x - nx));
            cnt[nx] -= 1;
            if (cnt[nx] == 0) q.push(nx);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, dist[i] + t[i]);
    cout << ans;




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}