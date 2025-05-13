// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
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
#include<tuple>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int arr[200001];
int ind[200001];
pii loop[200001];
bool visited[200001];
int loopsz[200001];
int mxidx[200001];
vector<int> rE[200001];

void dfs(int x) {
    if (loop[x].first != 0) return;
    dfs(arr[x]);
    loop[x] = loop[arr[x]];
    loop[x].second += 1;
}

void solve(int tc) {
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ind[arr[i]] += 1;
        loop[i] = { 0,0 };
        rE[arr[i]].push_back(i);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        visited[x] = true;
        ind[arr[x]] -= 1;
        if (ind[arr[x]] == 0) q.push(arr[x]);
    }

    int loopcnt = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        loopcnt += 1;
        loop[i] = { loopcnt,0 };
        loopsz[loopcnt] = 1;
        mxidx[loopcnt] = i;
        int x = arr[i];
        while (x != i) {
            visited[x] = true;
            loopsz[loopcnt] += 1;
            loop[x] = { loopcnt,0 };
            x = arr[x];
        }
    }


    for (int i = 1; i <= N; i++) {
        dfs(i);
        auto [idx, val] = loop[i];
        if (val > loop[mxidx[idx]].second) mxidx[idx] = i;
    }

    pii mx = { 0,0 };
    for (int i = 1; i <= loopcnt; i++) {
        int val = loopsz[i] + loop[mxidx[i]].second;
        if (val >= mx.first) mx = { val,mx.first };
        else mx.second = max(mx.second, val);
    }

    int ans = mx.first + mx.second;

    for (int i = 1; i <= N; i++) {
        visited[i] = (ind[i] != 0);
    }

    for (int i = 1; i <= loopcnt; i++) {
        int x = mxidx[i];
        while (!visited[x]) {
            visited[x] = true;
            x = arr[x];
        }
    }

    vector<int> ext(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) continue;
        q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans = max(ans, ext[x] + loopsz[loop[x].first] + loop[mxidx[loop[x].first]].second);
        for (int nx : rE[x]) {
            if (visited[nx]) continue;
            ext[nx] = ext[x] + 1;
            q.push(nx);
        }
    }

    cout << ans;
}
    



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}