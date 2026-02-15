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


ll arr[1000001];

ll tree[4000004];

void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] += 1;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x);
    update(node * 2 + 1, mid + 1, end, x);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int tc) {

    int N;
    cin >> N;
   
    for (int i = 1; i <= N; i++) cin >> arr[i];

    ll P;
    cin >> P;

    vector<ll> v(N + 1);
    v[0] = 0;
    for (int i = 1; i <= N; i++) {
        arr[i] -= P;
        arr[i] += arr[i - 1];
        v[i] = arr[i];
    }

    sort(v.begin(), v.end());

    ll ret = 0;
    for (int i = 0; i <= N; i++) {
        ll val = arr[i];
        ll r = upper_bound(v.begin(), v.end(), val) - v.begin();
        ret += get(1, 1, N + 1, 1, r);
        update(1, 1, N + 1, r);
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