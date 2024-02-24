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



int psum[100001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    psum[0] = 0;
    int ans = 0;
    int mn = 0;
    for (int i = 1; i <= N; i++) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
        if (i < M) continue;
        mn = min(mn, psum[i - M]);
        ans = max(ans, psum[i] - mn);
    }
    cout << ans;
    return 0;
}