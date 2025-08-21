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


int F[200001];
int B[200001];
int nx[200001];
ll psum[200001];
int f(int x) {
    if (F[x] == x) return x;
    else return F[x] = f(F[x]);
}

int b(int x) {
    if (B[x] == x) return x;
    else return B[x] = b(B[x]);
}

void solve(int tc) {

    int N;
    cin >> N;

    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        while (L--) {
            int x; cin >> x;
            arr[i].push_back(x);
        }
    }

    for (vector<int>& v : arr) {
        int L = v.size();
        for (int i = 0; i < L; i++) {
            F[v[i]] = v.front(); B[v[i]] = v.back();
            if (i != L - 1) nx[v[i]] = v[i + 1];
        }
    }

    int Q; cin >> Q;
    vector<tuple<int, int, int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        query[i] = { t,x,y };
        if (t == 1) {
            if (f(x) == f(y)) continue;
            nx[b(x)] = f(y);
            F[f(y)] = f(x);
            B[b(x)] = b(y);
        }
    }

    for (vector<int>& v : arr) {
        int x = v.front();
        if (f(x) != x) continue;
        psum[x] = x;
        while (nx[x] != 0) {
            psum[nx[x]] = nx[x] + psum[x];
            x = nx[x];
        }
    }

    for (vector<int>& v : arr) {
        int L = v.size();
        for (int i = 0; i < L; i++) {
            F[v[i]] = v.front(); 
        }
    }

    for (auto [t, x, y] : query) {
        if (t == 1) {
            if (f(x) == f(y)) {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            F[f(y)] = f(x);
        }
        else {
            if (f(x) != f(y)) {
                cout << -1 << endl;
                continue;
            }
            if (psum[x] > psum[y]) swap(x, y);
            cout << psum[y] - psum[x] + x << endl;
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