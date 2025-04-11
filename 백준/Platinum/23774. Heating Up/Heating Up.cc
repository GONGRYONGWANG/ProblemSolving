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
#define INF ll(9e18)
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

int N;
ll arr[500000];
ll psum[500000];
int tree[2000000];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    if (arr[tree[node * 2]] >= arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
    else tree[node] = tree[node * 2 + 1];
}

int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    int L = get(node * 2, start, mid, left, right);
    int R = get(node * 2 + 1, mid + 1, end, left, right);

    if (L == -1) return R;
    if (R == -1) return L;

    if (arr[L] >= arr[R]) return L;
    else return R;
}

ll dnc(int l, int r, ll x) {
    if (l > r) return INF;
    if (l == r) return max(x - arr[l], arr[l]);

    int mxidx = get(1, 1, N - 1, l, r);
    ll total = psum[r] - psum[l - 1];

    ll Lsum = psum[mxidx - 1] - psum[l - 1];
    ll Rsum = psum[r] - psum[mxidx];

    return min(dnc(l, mxidx - 1, max(arr[mxidx], x - arr[mxidx] - Rsum)), dnc(mxidx + 1, r, max(arr[mxidx], x - arr[mxidx] - Lsum)));
}

void solve(int tc) {

    cin >> N;

    vector<ll> v(N);
    ll mx = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    for (int i = 0; i < N; i++) {
        if (v[i] == mx) {
            for (int j = i; j < N; j++) {
                arr[j - i] = v[j];
            }
            for (int j = 0; j < i; j++) {
                arr[j + N - i] = v[j];
            }
            break;
        }
    }

    psum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        psum[i] = arr[i] + psum[i - 1];
    }
    
    makeTree(1, 1, N - 1);


    cout << dnc(1, N - 1, arr[0]);


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