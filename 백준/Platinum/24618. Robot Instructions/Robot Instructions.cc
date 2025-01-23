// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/gcctemplate_for_pbds&rope
#include<bits/stdc++.h>
#include<ext/rope>
/*
string s;
s.c_str() -> 스트링을 char arr로
rope<char> rp(s.c_str());
rp.insert(idx, s.c_str());
rp.insert(idx, some_char);'
cout<<rp.substr(idx, length);
*/
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") //SIMD



#define pq priority_queue
#define endl "\n"

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

const string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return powmod(x, mod - 2, mod);
}

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

ifstream fin; ofstream fout;
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };


string deb = "debug: ";


gp_hash_table<ll, gp_hash_table<ll, ll>> A[21];

void solve(int tc) {

    int N;
    cin >> N;

    pii g;
    cin >> g.first >> g.second;
    vector<pll> arr(N);
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        arr[i] = { x,y };
    }

    vector<ll> ans(N + 1, 0);

    if (N <= 20) {
        for (int i = 0; i < (1 << N); i++) {
            ll x = 0; ll y = 0; ll cnt = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    x += arr[j].first;
                    y += arr[j].second;
                    cnt += 1;
                }
            }
            if (g.first == x && g.second == y) ans[cnt] += 1;
        }

        for (int K = 1; K <= N; K++) cout << ans[K] << endl;
        return;
    }

    for (int i = 0; i < (1 << 20); i++) {
        ll x = 0; ll y = 0; ll cnt = 0;
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j)) {
                x += arr[j].first;
                y += arr[j].second;
                cnt += 1;
            }
        }
        A[cnt][x][y] += 1;
    }

    for (int i = 0; i < (1 << (N - 20)); i++) {
        ll x = 0; ll y = 0; ll cnt = 0;
        for (int j = 0; j < N - 20; j++) {
            if (i & (1 << j)) {
                x += arr[j + 20].first;
                y += arr[j + 20].second;
                cnt += 1;
            }
        }
        for (int k = 0; k <= 20; k++) {
            if (A[k].find(g.first - x) == A[k].end()) continue;
            if (A[k][g.first - x].find(g.second - y) == A[k][g.first - x].end()) continue;
            ans[k + cnt] += A[k][g.first - x][g.second - y];
        }
    }

    for (int K = 1; K <= N; K++) cout << ans[K] << endl;

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    //fin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}
