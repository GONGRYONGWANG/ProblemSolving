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
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int tree[400000];
void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    tree[node] += 1;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x); update(node * 2 + 1, mid + 1, end, x);
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
    vector<int> comp(N);
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        comp[x] = i;
    }

    ll ret = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        x = comp[x];
        ll g = get(1, 1, N, 1, x);
        ret += g * (N - i - x + g);
        update(1, 1, N, x);
    }

    if (ret == 0) cout << "Attention is what I want";
    else {
        cout << "My heart has gone to paradise" << endl;
        cout << ret;
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