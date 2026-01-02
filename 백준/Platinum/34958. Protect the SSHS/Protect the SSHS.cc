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


vector<pll> E[100001];
ll dist1[100001];
ll dist2[100001];

struct pqcmp {
    bool operator()(pll& A, pll& B) {
        return A.second > B.second;
    }
};


void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        ll u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    pq<pll, vector<pll>, pqcmp> q;

    q.push({ 1,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (dist1[x]) continue;
        dist1[x] = d;
        for (auto [nx, w] : E[x]) {
            if (dist1[nx]) continue;
            q.push({ nx,d + w });
        }
    }

    q.push({ N,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (dist2[x]) continue;
        dist2[x] = d;
        for (auto [nx, w] : E[x]) {
            if (dist2[nx]) continue;
            q.push({ nx,d + w });
        }
    }

    vector<vector<ll>> init;
    for (int i = 1; i <= N; i++) {
        init.push_back({ dist1[i] - 1, dist2[i] - 1, i });
    }

    sort(init.begin(), init.end());

    vector<vector<ll>> arr;
    arr.push_back({ 0,inf });
    for (int i = 0; i < N; i++) {
        while (!arr.empty() && init[i][1] >= arr.back()[1]) arr.pop_back();
        arr.push_back(init[i]);
    }
    arr.push_back({ inf,0});



    int Q;
    cin >> Q;
    while (Q--) {
        ll a, b;
        cin >> a >> b;
        int l = 0;
        int r = arr.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m][0] * a < arr[m][1] * b) l = m + 1;
            else r = m;
        }

        l = r - 1;
        if (arr[l][0] * a > arr[r][1] * b) cout << arr[l][2];
        else cout << arr[r][2];
        cout << endl;

    }






    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}