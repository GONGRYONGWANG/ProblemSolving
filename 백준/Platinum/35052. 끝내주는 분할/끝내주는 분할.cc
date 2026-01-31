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

int A[300000];
int B[300000];
int treeA[1200000];
int treeB[1200000];

void update(int* tree, int node, int start, int end, int x, int v) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] += v;
        return;
    }
    int mid = (start + end) / 2;
    update(tree, node * 2, start, mid, x, v);
    update(tree, node * 2 + 1, mid + 1, end, x, v);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int get(int* tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(tree, node * 2, start, mid, left, right) + get(tree, node * 2 + 1, mid + 1, end, left, right);
}

int nx[300000];

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int s = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i]; int b = B[i];
        while (get(treeA, 1, 1, N, 1, a) != get(treeB, 1, 1, N, 1, b)) {
            update(treeA, 1, 1, N, A[s], -1);
            update(treeB, 1, 1, N, B[s], -1);
            s += 1;
        }
        update(treeA, 1, 1, N, a, 1);
        update(treeB, 1, 1, N, b, 1);
        nx[i] = s - 1;
    }

    int ret = 0;
    int x = N - 1;
    while (x != -1) {
        ret += 1;
        x = nx[x];
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