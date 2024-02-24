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

    int N;
    cin >> N;
    vector<pii> arr(N+1);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    arr[N] = { 0,0 };
    sort(arr.rbegin(), arr.rend());

    int ans = 0;
    pq<int> q;
    int day = N;
    for (int i = 0; i <= N; i++) {
        while (day > arr[i].first) {
            day -= 1;
            if (q.empty()) {
                day = arr[i].first;
                break;
            }
            ans += q.top();
            q.pop();
        }
        q.push(arr[i].second);
    }
    cout << ans;
    return 0;
}