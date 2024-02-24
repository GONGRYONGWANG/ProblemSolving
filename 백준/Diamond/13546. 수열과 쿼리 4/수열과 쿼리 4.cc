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


int N, K, M;
int sqrtN;
bool cmp(vector<int> a, vector<int> b) {
    if (a[0] / sqrtN == b[0]/ sqrtN) return a[1] < b[1];
    return a[0] / sqrtN < b[0] / sqrtN;
}

int A[100001];
deque<int> dq[100001];
int distnum[100000];
int dist[100001];
int maxdist;
int ans[100000];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> K;
    sqrtN = (int)sqrt(N);
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

    maxdist = 0;
    distnum[0] = 100000;
    int s, e , idx;
    s = Q[0][0];
    e = Q[0][1];
    idx = Q[0][2];
    for (int i = s; i <= e; i++) {
        distnum[dist[A[i]]] -= 1;
        dq[A[i]].push_back(i);
        dist[A[i]] = dq[A[i]].back() - dq[A[i]].front();
        distnum[dist[A[i]]] += 1;
        maxdist = max(maxdist, dist[A[i]]);
    }
    ans[idx] = maxdist;
    for (int i = 1; i < M; i++) {
        int l = Q[i][0];
        int r = Q[i][1];
        idx = Q[i][2];
        while (l < s) {
            s -= 1;
            distnum[dist[A[s]]] -= 1;
            dq[A[s]].push_front(s);
            dist[A[s]] = dq[A[s]].back() - dq[A[s]].front();
            distnum[dist[A[s]]] += 1;
            maxdist = max(maxdist, dist[A[s]]);
        }
        while (e < r) {
            e += 1;
            distnum[dist[A[e]]] -= 1;
            dq[A[e]].push_back(e);
            dist[A[e]] = dq[A[e]].back() - dq[A[e]].front();
            distnum[dist[A[e]]] += 1;
            maxdist = max(maxdist, dist[A[e]]);
        }
        while (s < l) {
            distnum[dist[A[s]]] -= 1;
            dq[A[s]].pop_front();
            if (dq[A[s]].empty()) {
                dist[A[s]] = 0;
            }
            else dist[A[s]] = dq[A[s]].back() - dq[A[s]].front();
            distnum[dist[A[s]]] += 1;
            s += 1;
        }
        while (r < e) {
            distnum[dist[A[e]]] -= 1;
            dq[A[e]].pop_back();
            if (dq[A[e]].empty()) {
                dist[A[e]] = 0;
            }
            else dist[A[e]] = dq[A[e]].back() - dq[A[e]].front();
            distnum[dist[A[e]]] += 1;
            e -= 1;
        }
        while (!distnum[maxdist]) {
            maxdist -= 1;
        }
        ans[idx] = maxdist;
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}