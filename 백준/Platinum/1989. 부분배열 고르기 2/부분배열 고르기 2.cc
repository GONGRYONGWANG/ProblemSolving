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



ll psum[100001];
int l[100001];
int r[100001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;
    psum[0] = 0;
    stack<pii> lst;
    for (int i = 1; i <= N; i++) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
        while (!lst.empty() && lst.top().first >= psum[i]-psum[i-1]) {
            lst.pop();
        }

        if (lst.empty()) {
            l[i] = 1;
        }
        else l[i] = lst.top().second + 1;

        lst.push({ psum[i] - psum[i - 1],i });
    }
    stack<pii> rst;
    for (int i = N; i >= 1; i--) {
        while (!rst.empty() && rst.top().first >= psum[i] - psum[i - 1]) {
            rst.pop();
        }

        if (rst.empty()) {
            r[i] = N;
        }
        else r[i] = rst.top().second - 1;

        rst.push({ psum[i] - psum[i - 1],i });
    }
    ll ans = 0;
    int s, e;
    for (int i = 1; i <= N; i++) {
        if ((psum[i] - psum[i - 1]) * (psum[r[i]] - psum[l[i] - 1]) >= ans) {
            ans = (psum[i] - psum[i - 1]) * (psum[r[i]] - psum[l[i] - 1]);
            s = l[i];
            e = r[i];
        }
    }
    cout << ans << endl << s << " " << e;

    return 0;
}