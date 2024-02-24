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



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> pos, neg;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 0) pos.push_back(x);
        else neg.push_back(-x);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int ans = 0;
    int mx = 0;
    for (int i = pos.size() - 1; i >= 0; i -= M) {
        ans += 2 * pos[i];
        mx = max(mx, pos[i]);
    }
    for (int i = neg.size() - 1; i >= 0; i -= M) {
        ans += 2 * neg[i];
        mx = max(mx, neg[i]);
    }
    cout << ans - mx;
    
    return 0;
}