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

ll mod = 1e9 + 7;
ll tree[10][400000];

void update(int node, int start, int end, int idx, ll val, int k) {
    if (idx > end || idx < start) return;
    if (start == end) {
        tree[k][node] = (tree[k][node] + val) % mod;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val, k); update(node * 2 + 1, mid + 1, end, idx, val, k);
    tree[k][node] = (tree[k][node * 2] + tree[k][node * 2 + 1]) % mod;
}

ll get(int node, int start, int end, int left, int right, int k) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[k][node];
    int mid = (start + end) / 2;
    return (get(node * 2, start, mid, left, right, k) + get(node * 2 + 1, mid + 1, end, left, right, k)) % mod;
}


void solve(int tc) {

    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (x != 1) {
            ans += get(1, 1, N, 1, x - 1, 9);
            ans %= mod;
            for (int k = 9; k >= 1; k--) {
                update(1, 1, N, x, get(1, 1, N, 1, x - 1, k - 1), k);
            }
        }
        update(1, 1, N, x, 1, 0);
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