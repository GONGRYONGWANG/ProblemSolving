// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
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

ll tree[4000000][10];
short lazy[4000000][10];
short arr[1000001];
ll mod = 998244353;
ll pow10mod[1000001];
void makeTree(int node, int start, int end) {
    for (int i = 0; i < 10; i++) lazy[node][i] = i;
    if (start == end) {
        tree[node][arr[start]] = 1;
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    for (int i = 0; i < 10; i++) {
        tree[node][i] = (tree[node * 2][i] * pow10mod[end - mid] + tree[node * 2 + 1][i]) % mod;
    }
}

void lazyProp(int node, int start, int end) {
    vector<ll> tmp(10, 0);
    for (int i = 0; i < 10; i++) {
        tmp[lazy[node][i]] += tree[node][i];
    }
    for (int i = 0; i < 10; i++) {
        tree[node][i] = tmp[i];
    }
    if (start != end) {
        for (int i = 0; i < 10; i++) {
            lazy[node * 2][i] = lazy[node][lazy[node * 2][i]];
            lazy[node * 2 + 1][i] = lazy[node][lazy[node * 2 + 1][i]];
        }
    }
    for (int i = 0; i < 10; i++) lazy[node][i] = i;
}

void update(int node, int start, int end, int left, int right, int f, int t) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node][f] = t;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, f, t); update(node * 2 + 1, mid + 1, end, left, right, f, t);
    for (int i = 0; i < 10; i++) {
        tree[node][i] = (tree[node * 2][i] * pow10mod[end - mid] + tree[node * 2 + 1][i]) % mod;
    }
}
pll get(int node, int start, int end, int left, int right) {
    lazyProp(node, start, end);
    if (left > end || right < start) return { 0,0 };
    if (left <= start && right >= end) {
        ll ret = 0;
        for (int i = 0; i < 10; i++) {
            ret += tree[node][i] * i % mod;
            ret %= mod;
        }
        return { ret,end - start + 1 };
    }
    int mid = (start + end) / 2;
    pll L = get(node * 2, start, mid, left, right);
    pll R = get(node * 2 + 1, mid + 1, end, left, right);
    return { (L.first * pow10mod[R.second] + R.first) % mod,L.second + R.second };
}

void solve(int tc) {

    string s;
    cin >> s;
    int N = s.length();
    for (int i = 0; i < N; i++) {
        arr[i + 1] = s[i] - '0';
    }

    pow10mod[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow10mod[i] = pow10mod[i - 1] * 10 % mod;
    }

    makeTree(1, 1, N);

    int Q;
    cin >> Q;
    while (Q--) {
        int x, i, j, f, t;
        cin >> x >> i >> j;
        if (x == 1) {
            cin >> f >> t;
            update(1, 1, N, i, j, f, t);
        }
        else {
            cout << get(1, 1, N, i, j).first << endl;
        }
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