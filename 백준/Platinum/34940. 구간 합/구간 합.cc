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

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

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

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll up[1000002];
ll upcnt[1000002];
ll down[1000002];
ll downcnt[1000002];
ll flat[1000002];
ll arr[1000002];

ll mod = 1e9 + 7;

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (N--) {
        ll s, e, v;
        cin >> s >> e >> v;
        ll a = s - 1; ll b = M - e;
        ll l = e - s + 1;

        if (a > b) swap(a, b);

        up[l] += v;
        upcnt[l] += v;
        up[l + a + 1] -= (a + 2) * v;
        upcnt[l + a + 1] -= v;

        flat[l + a + 1] += (a + 1) * v;
        flat[l + b] -= (a + 1) * v;

        down[l + b] += (a + 1) * v;
        downcnt[l + b] += v;

    }

    ll ret = 1;

    for (int i = 1; i <= M; i++) {
        arr[i] = up[i] + down[i] + flat[i];
        
        arr[i] %= mod - 1;
        ret = ret * powmod(i, arr[i], mod) % mod;


        up[i + 1] += up[i] + upcnt[i];
        upcnt[i + 1] += upcnt[i];
        down[i + 1] += down[i] - downcnt[i];
        downcnt[i + 1] += downcnt[i];
        flat[i + 1] += flat[i];
    }

    cout << ret;





    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}