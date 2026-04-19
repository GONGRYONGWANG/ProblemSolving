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
using ll = long long;
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

struct treeNode {
    pii mx = { 0,0 }, L = { 0,0 }, R = { 0,0 };
    treeNode(pii mx, pii L, pii R) :mx(mx), L(L), R(R) {}
    treeNode() {}


};

int arr[300001];
treeNode tree[1200000];

treeNode mer(treeNode A, treeNode B) {
    if (B.mx.first == 0) return A;
    if (A.mx.first == 0) return B;

    if (arr[A.mx.first] > arr[B.mx.first]) return{ A.mx,A.L,B.R };
    if (arr[A.mx.first] < arr[B.mx.first]) return{ B.mx,A.L,B.R };

    treeNode ret;
    if (A.mx.second - A.mx.first >= B.mx.second - B.mx.first) ret.mx = A.mx;
    else ret.mx = B.mx;

    if (arr[A.R.first] == arr[ret.mx.first] && arr[B.L.first] == arr[ret.mx.first]) {
        if (B.L.second - A.R.first > ret.mx.second - ret.mx.first) ret.mx = { A.R.first,B.L.second };
        else if (B.L.second - A.R.first == ret.mx.second - ret.mx.first && A.R.first < ret.mx.first) ret.mx = { A.R.first,B.L.second };
    }

    if (A.L.first == A.R.first && arr[A.L.first] == arr[B.L.first]) ret.L = { A.L.first, B.L.second };
    else ret.L = A.L;

    if (B.R.first == B.L.first && arr[B.R.first] == arr[A.R.first]) ret.R = { A.R.first,B.R.second };
    else ret.R = B.R;

    return ret;

}

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = { {start,start},{start,start},{start,start} };
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x); update(node * 2 + 1, mid + 1, end, x);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

treeNode get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return { {0,0},{0,0},{0,0} };
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}


void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    makeTree(1, 1, N);

    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        arr[x] = y;
        update(1, 1, N, x);
        cout << tree[1].mx.first << " " << tree[1].mx.second << endl;
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