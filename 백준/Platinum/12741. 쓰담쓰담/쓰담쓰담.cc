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

int arr[100001];
bool tree[400000];
void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = arr[x + 1] >= arr[x];
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x); update(node * 2 + 1, mid + 1, end, x);
    tree[node] = tree[node * 2] & tree[node * 2 + 1];
}
bool get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return true;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) & get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int tc) {
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i < N; i++) {
        update(1, 1, N - 1, i);
    }

    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            if (get(1, 1, N - 1, l, r - 1)) cout << "CS204";
            else cout << "HSS090";
            cout << endl;
        }
        else {
            swap(arr[l], arr[r]);
            if (l != 1) update(1, 1, N - 1, l - 1);
            if (l != N) update(1, 1, N - 1, l);
            if (r != 1) update(1, 1, N - 1, r - 1);
            if (r != N) update(1, 1, N - 1, r);
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