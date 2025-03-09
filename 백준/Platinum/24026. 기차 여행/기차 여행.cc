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

pii tree[800001][18];

pii mer(pii a, pii b) {
    return { min(a.first,b.first),max(a.second,b.second) };
}

void update(int node, int start, int end, int x, pii val, int k) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node][k] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, val, k);
    update(node * 2 + 1, mid + 1, end, x, val, k);
    tree[node][k] = mer(tree[node * 2][k], tree[node * 2 + 1][k]);
}

pii get(int node, int start, int end, int left, int right, int k) {
    if (left > end || right < start) return { inf,-inf };
    if (left <= start && right >= end) return tree[node][k];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right, k), get(node * 2 + 1, mid + 1, end, left, right, k));
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int l, r;
        cin >> l >> r;
        update(1, 1, N, i, { l,r }, 0);
    }

    for (int j = 1; j < 18; j++) {
        for (int i = 1; i <= N; i++) {
            pii p = get(1, 1, N, i, i, j - 1);
            update(1, 1, N, i, get(1, 1, N, p.first, p.second, j - 1), j);
        }
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            cout << 0 << endl;
            continue;
        }
        pii x = { u,u };
        int ret = 0;
        for (int j = 17; j >= 0; j--) {
            pii p = get(1, 1, N, x.first, x.second, j);
            if (p.first <= v && v <= p.second) continue;
            x = p;
            ret += (1 << j);
        }

        x = get(1, 1, N, x.first, x.second, 0);
        ret += 1;
        if (x.first <= v && v <= x.second) cout << ret;
        else cout << -1;
        cout << endl;

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