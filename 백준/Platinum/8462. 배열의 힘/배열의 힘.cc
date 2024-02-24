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


ll arr[100001];
ll ans[100000];
ll cnt[1000001];
vector<vector<int>> query;
const int sqrtN = 316;
bool cmp(vector<int> &a, vector<int> &b ){
    if (a[0] / sqrtN == b[0] / sqrtN) {
        return a[1] < b[1];
    }
    return a[0] / sqrtN < b[0] / sqrtN;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({ l,r,i });
    }
    sort(query.begin(), query.end(), cmp);

    int s = query[0][0];
    int e = query[0][1];

    ll ret = 0;

    for (int i = s; i <= e; i++) {
        ret -= cnt[arr[i]] * cnt[arr[i]] * arr[i];
        cnt[arr[i]] += 1;
        ret += cnt[arr[i]] * cnt[arr[i]] * arr[i];
    }
    ans[query[0][2]] = ret;

    for (int i = 1; i < M; i++) {
        int l = query[i][0];
        int r = query[i][1];
        while (l < s) {
            s -= 1;
            ret -= cnt[arr[s]] * cnt[arr[s]] * arr[s];
            cnt[arr[s]] += 1;
            ret += cnt[arr[s]] * cnt[arr[s]] * arr[s];
        }
        while (e < r) {
            e += 1;
            ret -= cnt[arr[e]] * cnt[arr[e]] * arr[e];
            cnt[arr[e]] += 1;
            ret += cnt[arr[e]] * cnt[arr[e]] * arr[e];
        }
        while (s < l) {
            ret -= cnt[arr[s]] * cnt[arr[s]] * arr[s];
            cnt[arr[s]] -= 1;
            ret += cnt[arr[s]] * cnt[arr[s]] * arr[s];
            s += 1;
        }
        while (r < e) {
            ret -= cnt[arr[e]] * cnt[arr[e]] * arr[e];
            cnt[arr[e]] -= 1;
            ret += cnt[arr[e]] * cnt[arr[e]] * arr[e];
            e -= 1;
        }
        ans[query[i][2]] = ret;
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}