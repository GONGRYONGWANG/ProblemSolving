#pragma warning(disable:4996) 
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


int N, M;
bool cmp(vector<int> a, vector<int> b) {
    int sqrtN = (int)sqrt(N);
    if (a[0] / sqrtN == b[0]/ sqrtN) return a[1] < b[1];
    return a[0] / sqrtN < b[0] / sqrtN;
}

int A[100001];
int cnt[100000];
int cntnum[100000];
int maxcnt;
int ans[100000];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    vector<vector<int>> Q;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        Q.push_back({ a - 1,b - 1, i });
    }
    sort(Q.begin(), Q.end(), cmp);

    maxcnt = 0;
    int s, e , idx;
    s = Q[0][0];
    e = Q[0][1];
    idx = Q[0][2];
    for (int i = s; i <= e; i++) {
        cntnum[cnt[A[i]]] -= 1;
        cnt[A[i]] += 1;
        cntnum[cnt[A[i]]] += 1;
        maxcnt = max(maxcnt, cnt[A[i]]);
    }
    ans[idx] = maxcnt;
    for (int i = 1; i < M; i++) {
        int l = Q[i][0];
        int r = Q[i][1];
        idx = Q[i][2];
        while (l < s) {
            s -= 1;
            cntnum[cnt[A[s]]] -= 1;
            cnt[A[s]] += 1;
            cntnum[cnt[A[s]]] += 1;
            maxcnt = max(maxcnt, cnt[A[s]]);
        }
        while (s < l) {
            if (maxcnt == cnt[A[s]] && cntnum[cnt[A[s]]] == 1) {
                maxcnt -= 1;
            }
            cntnum[cnt[A[s]]] -= 1;
            cnt[A[s]] -= 1;
            cntnum[cnt[A[s]]] += 1;
            s += 1;
        }
        while (e < r) {
            e += 1;
            cntnum[cnt[A[e]]] -= 1;
            cnt[A[e]] += 1;
            cntnum[cnt[A[e]]] += 1;
            maxcnt = max(maxcnt, cnt[A[e]]);
        }
        while (r < e) {
            if (maxcnt == cnt[A[e]] && cntnum[cnt[A[e]]] == 1) {
                maxcnt -= 1;
            }
            cntnum[cnt[A[e]]] -= 1;
            cnt[A[e]] -= 1;
            cntnum[cnt[A[e]]] += 1;
            e -= 1;
        }
        ans[idx] = maxcnt;
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}