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
#define INF ll(9e18)
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



vector<pll> E[200001];
vector<pll> rE[200001];
int ind[200001];

int L[200001];
ll sum[200001];
vector<int> arr[200001];
int idx[200001];
pll prv[200001];

bool cmp(int a, int b) {
    if (prv[a].second == prv[b].second)  return prv[a].first < prv[b].first;
    return prv[a].second < prv[b].second;
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[v].push_back({ u,w });
        rE[u].push_back({ v,w });
        ind[u] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) {
            q.push(i);
            L[i] = 0;
            sum[i] = 0;
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        arr[L[x]].push_back(x);
        for (pll& e : E[x]) {
            ind[e.first] -= 1;
            L[e.first] = max(L[e.first], L[x] + 1);
            if (ind[e.first] == 0) q.push(e.first);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int x : arr[i]) {
            prv[x] = { -1,inf };
            for (pll& e : rE[x]) {
                if (L[e.first] != L[x] - 1) continue;
                if (e.second < prv[x].second) prv[x] = e;
                else if (e.second == prv[x].second && idx[e.first] < idx[prv[x].first]) prv[x] = e;
            }
            sum[x] = sum[prv[x].first] + prv[x].second;
            prv[x].first = idx[prv[x].first];
        }
        sort(arr[i].begin(), arr[i].end(), cmp);
        for (int j = 0; j < arr[i].size(); j++) {
            idx[arr[i][j]] = j;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << L[i] << " " << sum[i] << endl;
    }

    





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