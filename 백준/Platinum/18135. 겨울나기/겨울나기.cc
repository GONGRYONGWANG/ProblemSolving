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

int P[2000001];
ll tree[4000000];
ll lazy[4000000];
void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int start, int end, int left, int right, ll v) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] += v;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, v);
    update(node * 2 + 1, mid + 1, end, left, right, v);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        update(1, 1, M, i, i, c);
        for (int j = a; j <= b; j++) P[j] = i;
    }

    while (1) {
        int t;
        cin >> t;
        if (t == 0) {
            cin >> t >> t;
            break;
        }
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x = P[x]; y = P[y];
            if (x <= y) cout << get(1, 1, M, x, y);
            else cout << get(1, 1, M, x, M) + get(1, 1, M, 1, y);
            cout << endl;
        }
        else {
            int x, y, z;
            cin >> x >> y >> z;
            x = P[x]; y = P[y];
            if (x <= y) update(1, 1, M, x, y, z);
            else {
                update(1, 1, M, x, M, z); update(1, 1, M, 1, y, z);
            }
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