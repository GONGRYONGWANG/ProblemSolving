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
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
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
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int arr[250001];
int tree[1000000][10];
int lazy[1000000];

vector<int> mer(vector<int> a, vector<int> b) {
    vector<int> ret(10);
    for (int i = 0; i < 10; i++) {
        ret[i] = a[i] + b[i];
    }
    return ret;
}

void makeTree(int node, int start, int end) {
    lazy[node] = 0;
    if (start == end) {
        tree[node][arr[start]] = 1;
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    for (int i = 0; i < 10; i++) tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
}

int tmp[10];
void lazyProp(int node, int start, int end) {
    if (lazy[node] == 0) return;
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    for (int i = 0; i < 10; i++) {
        tmp[(i + lazy[node]) % 10] = tree[node][i];
    }
    for (int i = 0; i < 10; i++) tree[node][i] = tmp[i];
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] += 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right); update(node * 2 + 1, mid + 1, end, left, right);
    for (int i = 0; i < 10; i++) tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
}

int get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) {
        int ret = 0;
        for (int i = 0; i < 10; i++) ret += tree[node][i] * i;
        return ret;
    }
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        char x; cin >> x;
        arr[i] = (x - '0');
    }

    makeTree(1, 1, N);

    while (M--) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, N, l, r) << endl;
        update(1, 1, N, l, r);
    }



}
    


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}