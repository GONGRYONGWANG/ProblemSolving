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


int arr[101];
int nxt[101];
bool on[101];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    unordered_map<int, int> prvidx;
    for (int i = 0; i < K; i++) {
        nxt[i] = inf;
        cin >> arr[i];
        if (prvidx.count(arr[i])) {
            nxt[prvidx[arr[i]]] = i;
        }
        prvidx[arr[i]] = i;
    }
    pq<pii> q;
    int ans = 0;
    int slot = N;
    for (int i = 0; i < K; i++) {
        int node = arr[i];
        if (on[node]) {
            q.push({ nxt[i], arr[i] });
            continue;
        }
        if (slot != 0) {
            on[arr[i]] = true;
            slot -= 1;
            q.push({ nxt[i],arr[i] });
            continue;
        }
        ans += 1;
        on[arr[i]] = true;
        on[q.top().second] = false;
        q.pop();
        q.push({ nxt[i], arr[i] });
    }
    cout << ans;
    return 0;
}