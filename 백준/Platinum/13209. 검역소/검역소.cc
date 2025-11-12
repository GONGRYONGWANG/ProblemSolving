// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
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
#include<chrono>
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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<int> E[100001];
ll arr[100001];
vector<int> child[100001];
int parent[100001];
int ind[100001];
ll DP[100001];

void solve(int tc){

    int N, K;
    cin >> N >> K;
    
    ll l = 0; ll r = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        l = max(l, arr[i]); r += arr[i];
        E[i].clear();
        child[i].clear();
        ind[i] = 0;
        parent[i] = 0;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v); E[v].push_back(u);
    }

    int root;
    for (int i = 1; i <= N; i++) {
        if (E[i].size() == 1) root = i;
    }

    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            if (nx == parent[x]) continue;
            parent[nx] = x;
            child[x].push_back(nx);
            q.push(nx);
        }
    }

    while (l < r) {
        ll m = (l + r) / 2;

        for (int i = 1; i <= N; i++) {
            if (child[i].empty()) q.push(i);
            ind[i] = child[i].size();
        }

        int ret = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            vector<ll> v;
            for (int nx : child[x]) {
                v.push_back(DP[nx]);
            }

            sort(v.begin(), v.end());

            DP[x] = arr[x];
            for (ll val : v) {
                if (DP[x] + val > m) {
                    ret += 1;
                }
                else DP[x] += val;
            }

            if (x == root) continue;
            ind[parent[x]] -= 1;
            if (ind[parent[x]] == 0) q.push(parent[x]);
        }

        if (ret > K) l = m + 1;
        else r = m;
    }

    cout << l << endl;




    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}