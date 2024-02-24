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


pii arr[100000];
int ans;

bool cmp(pii a, pii b) {
    return a.second < b.second;
}

int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void clp(int l, int r) {
    if (r - l == 1) {
        ans = min(ans, dist(arr[l], arr[r]));
        return;
    }
    else if (r - l == 2) {
        ans = min(min(ans, dist(arr[l], arr[r])), min(dist(arr[l], arr[l + 1]), dist(arr[l + 1], arr[r])));
        return;
    }

    int m = (l + r) / 2;
    clp(l, m); clp(m + 1, r);
    vector<pii> v;
    for (int i = m; i >=l; i--) {
        if ((arr[m + 1].first - arr[i].first) * (arr[m + 1].first - arr[i].first) >= ans) break;
        v.push_back(arr[i]);
    }
    for (int i = m + 1; i <= r; i++) {
        if ((arr[m].first - arr[i].first) * (arr[m].first - arr[i].first) >= ans) break;
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if ((v[i].second - v[j].second) * (v[i].second - v[j].second) >= ans) break;
            ans = min(ans, dist(v[i], v[j]));
        }
    }

    return;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    sort(arr, arr + N);
    ans = inf;
    clp(0, N - 1);
    cout << ans;
    return 0;
}