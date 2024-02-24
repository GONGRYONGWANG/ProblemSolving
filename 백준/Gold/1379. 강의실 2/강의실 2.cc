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

int query[100001];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> v;
    for (int i = 0; i < N; i++) {
        int c, a, b;
        cin >> c >>a >> b;
        v.push_back({ a,b,c });
    }
    sort(v.begin(), v.end());
    
    int ans = 0;
    pq<pii, vector<pii>, greater<pii>> q;
    queue<int> slot;
    for (int i = 0; i < N; i++) {
        while (!q.empty() && q.top().first <= v[i][0]) {
            slot.push(q.top().second);
            q.pop();
        }
        if (slot.empty()) {
            ans += 1;
            q.push({ v[i][1],ans });
            query[v[i][2]] = ans;
        }
        else {
            q.push({ v[i][1],slot.front() });
            query[v[i][2]] = slot.front();
            slot.pop();
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= N; i++) {
        cout << query[i] << endl;
    }
    return 0;
}