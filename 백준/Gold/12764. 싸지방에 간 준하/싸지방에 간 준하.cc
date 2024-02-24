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
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

pii arr[100000];
int ans;
int cnt[100000];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + N);
    pq<int, vector<int>, greater<int>> slot;
    pq<pii, vector<pii>, greater<pii>> q;
    ans = 0;
    for (int i = 0; i < N; i++) {
        while (!q.empty() && q.top().first < arr[i].first) {
            slot.push(q.top().second);
            q.pop();
        }
        if (slot.empty()) {
            ans += 1;
            cnt[ans] = 1;
            q.push({ arr[i].second,ans });
        }
        else {
            int s = slot.top();
            slot.pop();
            cnt[s] += 1;
            q.push({ arr[i].second , s });
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        cout << cnt[i] << " ";
    }


    return 0;
}