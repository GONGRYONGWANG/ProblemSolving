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

int arr[100001];
int tree[400000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int rmq(int node, int start, int end, int left, int right) {
    if (left > right) return inf;
    if (left > end || right < start) return inf;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return min(rmq(node * 2, start, mid, left, right), rmq(node * 2 + 1, mid + 1, end, left, right));
}

int prv(int node, int start, int end, int left, int right, int x) {
    if (left > right) return 0;
    if (left > end || right < start) return 0;
    if (tree[node] > arr[x]) return 0;
    if (start == end) return start;
    int mid = (start + end) / 2;
    int R = prv(node * 2 + 1, mid + 1, end, left, right, x);
    if (R != 0) return R;
    else return prv(node * 2, start, mid, left, right, x);
}

int nxt(int node, int start, int end, int left, int right, int x) {
    if (left > right) return inf;
    if (left > end || right < start) return inf;
    if (tree[node] >= arr[x]) return inf;
    if (start == end) return start;
    int mid = (start + end) / 2;
    int L = nxt(node * 2, start, mid, left, right, x);
    if (L != inf) return L;
    else return nxt(node * 2 + 1, mid + 1, end, left, right, x);
}

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    K -= 1;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    makeTree(1, 1, N);


    ll ret = 0;

    for (int i = 1; i <= N; i++) {
        vector<ll> A = { i };
        while (A.size() <= K + 1) {
            int p = prv(1, 1, N, 1, A.back() - 1, i);
            if (p == 0) break;
            A.push_back(p);
        }
        A.push_back(0);

        vector<ll> B = { i };
        while (B.size() <= K + 1) {
            int n = nxt(1, 1, N, B.back() + 1, N, i);
            if (n == inf) break;
            B.push_back(n);
        }
        B.push_back(N + 1);

        for (int j = 0; j < A.size() - 1; j++) {
            A[j] = A[j] - A[j + 1];
        }
        A.pop_back();
        while (A.size() <= K + 1) A.push_back(0);

        for (int j = 0; j < B.size() - 1; j++) {
            B[j] = B[j + 1] - B[j];
        }
        B.pop_back();
        while (B.size() <= K + 1) B.push_back(0);

        for (int j = 0; j <= K; j++) {
            ret += A[j] * B[K - j] * arr[i];
        }

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