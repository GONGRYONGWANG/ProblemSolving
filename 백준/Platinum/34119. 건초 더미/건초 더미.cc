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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


bool cmp(vector<ll>& a, vector<ll>& b) {
    return a[2]< b[2];
}

pll tree[1200000];

void update(int node, int start, int end, int x, ll val) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = { 1,val };
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, val);
    update(node * 2 + 1, mid + 1, end, x, val);
    tree[node] = { tree[node * 2].first + tree[node * 2 + 1].first, tree[node * 2].second + tree[node * 2 + 1].second };
}

int get(int node, int start, int end, ll val) {
    if (val <= 0) return 0;
    if (start == end) return 1;
    int mid = (start + end) / 2;
    if (tree[node * 2].second < val) return tree[node * 2].first + get(node * 2 + 1, mid + 1, end, val - tree[node * 2].second);
    else return get(node * 2, start, mid, val);
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    vector<vector<ll>> arr(N);
    for (int i = 0; i < N; i++) {
        ll d; cin >> d;
        arr[i] = { d, 0 , i };
    }

    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < N; i++) {
        arr[i][1] = i + 1;
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<vector<ll>> query(Q);
    for (int i = 0; i < Q; i++) {
        ll x, p;
        cin >> x >> p;
        query[i] = { x,p,i };
    }
    sort(query.begin(), query.end());

    for (int i = 1; i < 4 * N; i++) {
        tree[i] = { 0,0 };
    }

    vector<int> ret(Q);

    int idx = 0;
    for (int i = 0; i < Q; i++) {
        ll x = query[i][0], p = query[i][1];

        while (idx != x) {
            update(1, 1, N, arr[idx][1], arr[idx][0]);
            idx += 1;
        }

        if (tree[1].second < p) {
            ret[query[i][2]] = -1;
            continue;
        }

        ret[query[i][2]] = get(1, 1, N, p);

    }

    for (int x : ret) cout << x << endl;













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