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
//const double pi = 3.14159265358979323846;


pii gs[10001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> gs[i].first >> gs[i].second;
    }
    sort(gs, gs + N);
    int P;
    cin >> gs[N].first >> P;
    pq<int> q;
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        while (P < gs[i].first) {
            if (q.empty()) {
                cout << -1;
                return 0;
            }
            P += q.top();
            q.pop();
            ans += 1;
        }
        q.push(gs[i].second);
    }
    cout << ans;

    return 0;
}