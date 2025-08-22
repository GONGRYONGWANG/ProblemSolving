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

vector<vector<ll>> arr[250001]; // {B, {C,D,E,A}}

pii Flight[1000000];// {C,B}
void initFlight(int node, int start, int end) {
    if (start == end) {
        Flight[node] = { arr[start].back()[0] , start };
        return;
    }
    int mid = (start + end) / 2;
    initFlight(node * 2, start, mid); initFlight(node * 2 + 1, mid + 1, end);
    Flight[node] = max(Flight[node * 2], Flight[node * 2 + 1]);

}
pii getFlight(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return { 0,0 };
    if (left <= start && right >= end) return Flight[node];
    int mid = (start + end) / 2;
    return max(getFlight(node * 2, start, mid, left, right), getFlight(node * 2 + 1, mid + 1, end, left, right));
}
void updateFlight(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        Flight[node] = { arr[start].back()[0] , start };
        return;
    }
    int mid = (start + end) / 2;
    updateFlight(node * 2, start, mid, x); updateFlight(node * 2 + 1, mid + 1, end, x);
    Flight[node] = max(Flight[node * 2], Flight[node * 2 + 1]);
}


pll mer(pll A, pll B) {
    return { A.first + B.first, min(A.second,B.second) };
}

pll tree[1000000]; // sz, mn
ll lazy[1000000];
void initTree(int node, int start, int end) {
    lazy[node] = INF;
    if (start == end) {
        tree[node] = { 1,INF - 1 };
        return;
    }
    int mid = (start + end) / 2;
    initTree(node * 2, start, mid); initTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void lazyProp(int node, int start, int end) {
    if (tree[node].first == 0) {
        tree[node].second = INF;
        return;
    }
    tree[node].second = min(tree[node].second, lazy[node]);
    if (start != end) {
        lazy[node * 2] = min(lazy[node * 2], lazy[node]);
        lazy[node * 2 + 1] = min(lazy[node * 2 + 1], lazy[node]);
    }
    lazy[node] = INF;
}

void update(int node, int start, int end, int left, int right, ll val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] = val;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

int get(int node, int start, int end) {
    lazyProp(node, start, end);
    if (start == end) return start;
    int mid = (start + end) / 2;
    lazyProp(node * 2, start, mid); lazyProp(node * 2 + 1, mid + 1, end);
    if (tree[node * 2].second == tree[node].second) return get(node * 2, start, mid);
    else return get(node * 2 + 1, mid + 1, end);
}

void pop(int node, int start, int end, int x) {
    lazyProp(node, start, end);
    if (x > end || x < start) return;
    if (start == end) {
        tree[node].first -= 1;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    pop(node * 2, start, mid, x); pop(node * 2 + 1, mid + 1, end, x);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}



void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; i++) {
        arr[i].push_back({ 0,0,0,0 });
    }

    while (M--) {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        arr[b].push_back({ c,d,e,a });
    }
    for (int i = 1; i <= N; i++) {
        sort(arr[i].rbegin(), arr[i].rend());
        reverse(arr[i].begin(), arr[i].end());
    }

    initFlight(1, 1, N);
    initTree(1, 1, N);
    update(1, 1, N, K, K, 0);

    vector<ll> ret(N + 1);

    for (int i = 0; i < N; i++) {
        int mnidx = get(1, 1, N);
        ret[mnidx] = tree[1].second;
        pop(1, 1, N, mnidx);
        while (1) {
            int Fidx = getFlight(1, 1, N, 1, mnidx).second;
            if (arr[Fidx].back()[0] < mnidx) break;
            update(1, 1, N, arr[Fidx].back()[1], arr[Fidx].back()[2], ret[mnidx] + arr[Fidx].back()[3]);
            arr[Fidx].pop_back();
            updateFlight(1, 1, N, Fidx);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (ret[i] == INF - 1) cout << -1;
        else cout << ret[i];
        cout << " ";
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