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

int N, Q;


ll arr[200001];
ll lazy[400];
int sz  = 316;
int L[200001];
int bckL[200001];

void update(int l, int r, ll a) {
    int lbck = l / sz; int rbck = r / sz;
    if (lbck == rbck) {
        for (int i = l; i <= r; i++) {
            arr[i] += a;
            L[i] = max(L[i], l);
        }
        return;
    }

    for (int i = l; i < (lbck + 1) * sz; i++) {
        arr[i] += a;
        L[i] = max(L[i], l);
    }

    for (int j = lbck + 1; j < rbck; j++) {
        lazy[j] += a;
        bckL[j] = max(bckL[j], l);
    }
    for (int i = rbck * sz; i <= r; i++) {
        arr[i] += a;
        L[i] = max(L[i], l);
    }

}

ll get(int x) {
    return arr[x] + lazy[x / sz];
}



int lca(ll x, ll y) {
    while (1) {
        x = max(x, 1ll); y = max(y, 1ll);
        if (x < y) swap(x, y);
        ll X = get(x); ll Y = get(y);
        if (X == Y && (x - y) % X == 0) return y;

        int l = max(L[x], bckL[x / sz]);
        x -= ((x - l) / X + 1) * X;

    }
}

void solve(int tc) {

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        arr[i] = 1;
        L[i] = 1;
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, a;
            cin >> x >> a;
            update(x, N, a);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << lca(x, y) << endl;
        }
    }

     


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