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


int N;
bool cmp(vector<int> a, vector<int> b) {
    int sqrtN = (int)sqrt(N);
    if (a[0] / sqrtN == b[0]/ sqrtN) return a[1] < b[1];
    return a[0] / sqrtN < b[0] / sqrtN;
}


int A[100000];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int M;
    cin >> M;
    vector<vector<int>> q;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        q.push_back({ a-1,b-1, i });
    }
    sort(q.begin(), q.end(), cmp);

    vector<int> ans(M);
    int s, e, idx;
    s = q[0][0];
    e = q[0][1];
    idx = q[0][2];
    int cnt = 0;
    unordered_map<int, int> m;
    for (int i = s; i <= e; i++) {
        if (!m[A[i]]) {
            cnt += 1;
        }
        m[A[i]] += 1;
    }
    ans[idx] = cnt;
    for (int i = 1; i < M; i++) {
        int l, r;
        l = q[i][0];
        r = q[i][1];
        idx = q[i][2];
        if (l < s) {
            for (int j = l; j < s; j++) {
                if (!m[A[j]]) {
                    cnt += 1;
                }
                m[A[j]] += 1;
            }
        }
        else {
            for (int j = s; j < l; j++) {
                m[A[j]] -= 1;
                if (!m[A[j]]) {
                    cnt -= 1;
                }
            }
        }

        if (r > e) {
            for (int j = e+1; j <= r; j++) {
                if (!m[A[j]]) {
                    cnt += 1;
                }
                m[A[j]] += 1;
            }
        }
        else {
            for (int j = r + 1; j <= e; j++) {
                m[A[j]] -= 1;
                if (!m[A[j]]) {
                    cnt -= 1;
                }
            }
        }
        s = l; e = r;
        ans[idx] = cnt;
    }


    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }



    return 0;
}