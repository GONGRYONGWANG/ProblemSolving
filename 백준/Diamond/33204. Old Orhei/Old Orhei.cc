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

int N, M;
vector<int> tree[400000];
pii E[100001];
int arr[100001];

vector<int> dummy;

vector<int> mer(vector<int> A, vector<int> B) {
    vector<int> ret(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ret[i] = B[A[i]];
    }
    return ret;
}

void makeTree(int node, int start, int end) {
    tree[node].resize(N + 1, 0);
    if (start == end) {
        auto& [u, v] = E[arr[start]];
        tree[node] = dummy;
        tree[node][u] = v;
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid);
    makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        auto& [u, v] = E[arr[start]];
        tree[node] = dummy;
        tree[node][u] = v;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x);
    update(node * 2 + 1, mid + 1, end, x);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}


vector<int> get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return dummy;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return mer(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int tc) {


    cin >> N >> M;

    dummy.resize(N + 1);
    for (int i = 0; i <= N; i++) dummy[i] = i;

    for (int i = 1; i <= M; i++) cin >> E[i].first >> E[i].second;

    int T; cin >> T;
    for (int i = 1; i <= T; i++) cin >> arr[i];

    makeTree(1, 1, T);


    int Q;
    cin >> Q;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int L, R, S;
            cin >> L >> R >> S;
            vector<int> v = get(1, 1, T, L, R);
            cout << v[S] << endl;
        }
        else {
            int i, K;
            cin >> i >> K;
            arr[i] = K;
            update(1, 1, T, i);
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