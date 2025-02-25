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

ll idxtoval[100001];

void update(int node, int start, int end, int x, vector<pll>& tree) {
    if (x<start || x>end) return;
    if (start == end) {
        tree[node].first += 1; tree[node].second += idxtoval[start];
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, tree); update(node * 2 + 1, mid + 1, end, x, tree);
    tree[node] = { tree[node * 2].first + tree[node * 2 + 1].first,tree[node * 2].second + tree[node * 2 + 1].second };
}

ll get(int node, int start, int end, int cnt, vector<pll>& tree) {
    if (tree[node].first == 0) return 0;
    if (start == end) {
        return idxtoval[start] * cnt;
    }
    int mid = (start + end) / 2;
    if (tree[node * 2 + 1].first > cnt) return get(node * 2 + 1, mid + 1, end, cnt, tree);
    return get(node * 2, start, mid, cnt - tree[node * 2 + 1].first, tree) + tree[node * 2 + 1].second;
}

void solve(int tc) {

    int N;
    cin >> N;
    vector<pll> arr(N);
    map<int,int> m;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
        m[arr[i].second] = 0;
    }
    sort(arr.begin(), arr.end());

    int cnt = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        cnt += 1;
        it->second = cnt;
        idxtoval[cnt] = it->first;
    }

    for (int i = 0; i < N; i++) {
        arr[i].second = m[arr[i].second];
    }

    int Q;
    cin >> Q;
    vector<pll> query(Q);
    vector<pll> lr(Q, { 0,N });
    for (int i = 0; i < Q; i++) cin >> query[i].first >> query[i].second;

    while (1) {

        vector<vector<int>> g(N + 1);
        bool f = false;
        for (int i = 0; i < Q; i++) {
            auto [l, r] = lr[i];
            if (l == r) continue;
            f = true;
            g[(l + r + 1) / 2].push_back(i);
        }

        if (!f) break;

        ll totalgold = 0; ll totalstone = 0;
        vector<pll> tree(4 * N, { 0,0 });
        for (int i = 0; i < N; i++) {
            auto [a, b] = arr[i];
            totalgold += a; totalstone += idxtoval[b];
            update(1, 1, N, b, tree);
            for (int x : g[i + 1]) {
                auto [l, r] = lr[x];
                ll extgold = query[x].first - totalgold;
                ll extstone = query[x].second - totalstone;
                if (extgold < 0) {
                    lr[x].second = (l + r + 1) / 2 - 1;
                    continue;
                }
                if (extgold >= (l + r + 1) / 2 || extstone >= 0) {
                    lr[x].first = (l + r + 1) / 2;
                    continue;
                }
                if (extgold == 0 && extstone < 0) {
                    lr[x].second = (l + r + 1) / 2 - 1;
                    continue;
                }

                if (extstone + get(1, 1, N, extgold, tree) >= 0) {
                    lr[x].first = (l + r + 1) / 2;
                }
                else lr[x].second = (l + r + 1) / 2 - 1;
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << lr[i].first << endl;
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