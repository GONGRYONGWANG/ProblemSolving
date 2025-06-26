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
#define INF ll(4e18)
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



int arr[400001];
pll tree[400000]; // cnt, sum

pll mer(pll& a, pll& b) {
    return { a.first + b.first, a.second + b.second };
}

void add(int node, int start, int end, int idx) {
    if (idx > end || idx < start) return;
    if (start == end) {
        tree[node].first += 1;
        tree[node].second += start;
        return;
    }
    int mid = (start + end) / 2;
    add(node * 2, start, mid, idx);
    add(node * 2 + 1, mid + 1, end, idx);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

void sub(int node, int start, int end, int idx) {
    if (idx > end || idx < start) return;
    if (start == end) {
        tree[node].first -= 1;
        tree[node].second -= start;
        return;
    }
    int mid = (start + end) / 2;
    sub(node * 2, start, mid, idx);
    sub(node * 2 + 1, mid + 1, end, idx);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}

int get(int node, int start, int end, ll t) {
    if (t >= tree[node].second) return tree[node].first;
    if (start == end) return t / start;
    int mid = (start + end) / 2;
    if (tree[node * 2].second > t) {
        return get(node * 2, start, mid, t);
    }
    else {
        return tree[node * 2].first + get(node * 2 + 1, mid + 1, end, t - tree[node * 2].second);
    }
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        add(1, 1, 100000, arr[i]);
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, v;
            cin >> idx >> v;
            sub(1, 1, 100000, arr[idx]);
            arr[idx] = v;
            add(1, 1, 100000, arr[idx]);
        }
        else if (t == 2) {
            ll T;
            cin >> T;
            cout << get(1, 1, 100000, T) << endl;
        }
        else {
            N += 1;
            cin >> arr[N];
            add(1, 1, 100000, arr[N]);
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