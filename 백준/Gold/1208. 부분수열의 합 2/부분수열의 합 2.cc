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

int N, S;
int arr[40];
vector<int> l, r;

void makeL(int x, int val) {
    if (x == N / 2) {
        l.push_back(val);
        return;
    }
    makeL(x + 1, val + arr[x]);
    makeL(x + 1, val);
}

void makeR(int x, int val) {
    if (x == N) {
        r.push_back(val);
        return;
    }
    makeR(x + 1, val + arr[x]);
    makeR(x + 1, val);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    makeL(0,0);
    makeR(N/2, 0);

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    long long ans = 0;
    for (int i = 0; i < l.size(); i++) {
        ans += upper_bound(r.begin(), r.end(), S - l[i]) - lower_bound(r.begin(), r.end(), S - l[i]);
    }
    if (S == 0) ans -= 1;
    cout << ans;
    return 0;
}