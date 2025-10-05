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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<int> child[100000];
ll d[100000];
void init(int x) {
    d[x] = 1;
    for (int nx : child[x]) {
        init(nx);
        d[x] = max(d[x], 1 + d[nx]);
    }
}

pq<pll> q;

void dfs(int x) {
    if (d[x] == 1) return;

    int nx = -1;
    for (int c : child[x]) {
        if (nx == -1 || d[c] > d[nx]) nx = c;
    }
    for (int c : child[x]) {
        if (c != nx) q.push({ d[c],c });
    }
    dfs(nx);
}

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    vector<ll> arr(K);
    for (int i = 0; i < K; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());

    for (int i = 1; i < N; i++){
        int p; cin >> p;
        child[p].push_back(i);
    }

    init(0);

    ll ans = -arr.front();

    q.push({ d[0],0 });
    for (ll v : arr) {
        int x = q.top().second;
        q.pop();
        ans += v * d[x];
        dfs(x);
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