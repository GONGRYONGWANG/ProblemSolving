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

int arr[300];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int l = 1;
    int r = 30000;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        l = max(l, arr[i]);
    }

    while (l <= r) {
        int m = (l + r) / 2;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (sum + arr[i] > m) {
                cnt += 1;
                sum = 0;
            }
            sum += arr[i];
        }
        cnt += 1;
        if (cnt > M) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << l << endl;

    int cnt = 0;
    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (sum + arr[i] > l) {
            ans.push_back(cnt);
            cnt = 0;
            sum = 0;
        }
        sum += arr[i];
        cnt += 1;
    }
    ans.push_back(cnt);

    int extra = M - ans.size();
    for (int i = 0; i < ans.size(); i++) {
        while (ans[i] != 1 && extra != 0) {
            cout << 1<<" ";
            extra -= 1;
            ans[i] -= 1;
        }
        cout << ans[i]<<" ";
    }



    return 0;
}