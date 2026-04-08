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

map<int, vector<int>> m;
pii arr[250001];
ll W[250001];

struct treeNode {
    int Lt = 0, Rt = 0;
    ll v = 0; ll lmx = 0; ll rmx = 0;
    treeNode(ll Lt, ll Rt, ll v, ll lmx, ll rmx) : Lt(Lt), Rt(Rt), v(v), lmx(lmx), rmx(rmx) {};
    treeNode() {};
};

treeNode tree[1000000];

treeNode mer(treeNode A, treeNode B) {
    if (A.v == 0) return B;
    if (B.v == 0) return A;
    if (A.Rt != B.Lt) return { A.Lt,B.Rt, A.v + B.v,A.lmx,B.rmx };
    if (A.lmx == A.v && B.rmx == B.v) return { A.Lt, B.Rt,max(A.v,B.v),max(A.v,B.v),max(A.v,B.v) };
    if (A.lmx == A.v) return { A.Lt, B.Rt,max(A.v,B.lmx) + B.v - B.lmx, max(A.v,B.lmx),B.rmx };
    if (B.rmx == B.v) return { A.Lt, B.Rt, A.v - A.rmx + max(A.rmx,B.v), A.lmx, max(A.rmx,B.v) };
    return { A.Lt,B.Rt,A.v - A.rmx + B.v - B.lmx + max(A.rmx,B.lmx), A.lmx, B.rmx };
}

void update(int node, int start, int end, int x, int t, ll v) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = { t,t,v,v,v };
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, t, v);
    update(node * 2 + 1, mid + 1, end, x, t, v);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void solve(int tc) {

    int N;
    cin >> N;

    map<int, int> ycomp;
    for (int i = 1; i <= N; i++) {
        int l, r, y, t;
        char c;
        cin >> l >> r >> y >> c;
        t = (c == 'S');
        arr[i] = { y,t };
        W[i] = r - l + 1;
        m[l].push_back(i);
        m[r + 1].push_back(-i);
        ycomp[y] = 1;
    }

    for (auto it = next(ycomp.begin()); it != ycomp.end(); it++) {
        it->second = prev(it)->second + 1;
    }

    for (int i = 1; i <= N; i++) arr[i].first = ycomp[arr[i].first];

    ll ret = 0;

    for (auto it = m.begin(); it != m.end(); it++) {
        vector<int> v = it->second;
        vector<int> A, B;
        for (int& x : v) {
            if (x < 0) A.push_back(-x);
            else B.push_back(x);
        }
        for (int& x : A) {
            update(1, 1, N, arr[x].first, 0, 0);
        }
        for (int& x : B) {
            update(1, 1, N, arr[x].first, arr[x].second, W[x]);
        }
        ret = max(ret, tree[1].v);
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