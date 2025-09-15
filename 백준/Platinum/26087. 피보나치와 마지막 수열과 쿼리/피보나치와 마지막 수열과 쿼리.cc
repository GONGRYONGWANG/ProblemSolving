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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


ll F[1000001];
ll mod = 1e9 + 7;

int tree[4000000];
void lazyProp(int node, int start, int end) {
    if (tree[node] == -1 || start == end) return;
    tree[node * 2] = tree[node];
    tree[node * 2 + 1] = tree[node];
    tree[node] = -1;
}
void update(int node, int start, int end, int left, int right, int x) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        tree[node] = x;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, x);
    update(node * 2 + 1, mid + 1, end, left, right, x);
}

int ret[1000001];
void get(int node, int start, int end) {
    lazyProp(node, start, end);
    if (start == end) {
        ret[start] = tree[node];
        return;
    }
    int mid = (start + end) / 2;
    get(node * 2, start, mid);
    get(node * 2 + 1, mid + 1, end);
}

void solve(int tc) {
    int N, Q;
    cin >> N >> Q;
    F[0] = 1; F[1] = 1;
    for (int i = 2; i <= N; i++){
        F[i] = (F[i - 1] + F[i - 2]) % mod;
    }

    for (int i = 1; i < 4 * N; i++) {
        tree[i] = -1;
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        update(1, 1, N, l, r, l - 1);
    }

    get(1, 1, N);
    for (int i = 1; i <= N; i++) {
        if (ret[i] == -1) {
            cout << 0 << " ";
        }
        else cout << F[i - ret[i]] << " ";
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