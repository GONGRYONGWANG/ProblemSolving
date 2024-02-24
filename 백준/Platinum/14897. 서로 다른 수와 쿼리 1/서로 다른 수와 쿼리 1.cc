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


unordered_map<int, int> compress;
int arr[1000001];
int cnt[1000001];
vector<vector<int>> Q;
int ans[1000000];

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] / 1000 == b[0] / 1000) {
        return a[1] < b[1];
    }
    return a[0] / 1000 < b[0] / 1000;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (!compress.count(arr[i])) {
            compress[arr[i]] = i;
        }
        arr[i] = compress[arr[i]];
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        Q.push_back({ l,r,i });
    }
    sort(Q.begin(), Q.end(), cmp);

    int s = Q[0][0];
    int e = Q[0][1];
    int ret = 0;
    for (int i = s; i <= e; i++) {
        if (cnt[arr[i]] == 0) ret += 1;
        cnt[arr[i]] += 1;
    }
    ans[Q[0][2]] = ret;

    for (int i = 1; i < M; i++) {
        int l = Q[i][0];
        int r = Q[i][1];
        while (l < s) {
            s -= 1;
            if (cnt[arr[s]] == 0) ret += 1;
            cnt[arr[s]] += 1;
        }
        while (e < r) {
            e += 1;
            if (cnt[arr[e]] == 0) ret += 1;
            cnt[arr[e]] += 1;
        }
        while (s < l) {
            cnt[arr[s]] -= 1;
            if (cnt[arr[s]] == 0) ret -= 1;
            s += 1;
        }
        while (r < e) {
            cnt[arr[e]] -= 1;
            if (cnt[arr[e]] == 0) ret -= 1;
            e -= 1;
        }
        ans[Q[i][2]] = ret;
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}