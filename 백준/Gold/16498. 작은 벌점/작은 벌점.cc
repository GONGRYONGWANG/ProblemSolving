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
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;
    vector<int> a, b, c;
    for (int i = 0; i < A; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < B; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        c.push_back(x);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    int ans = inf*2+1;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int l = min(a[i], b[j]);
            int r = max(a[i], b[j]);
            if (r - l >= ans) continue;
            auto lb = lower_bound(c.begin(), c.end(), l);
            int ret;
            if (lb == c.end()) {
                ret = r - *(--lb);
            }
            else if (*lb <= r) {
                ret = r - l;
            }
            else if(lb == c.begin()){
                ret = *lb - l;
            }
            else {
                ret = min(r - *(--lb), *lb - l);
            }
            ans = min(ans, ret);
        }
    }
    cout << ans;


    return 0;
}