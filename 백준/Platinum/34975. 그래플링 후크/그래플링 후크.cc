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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


pii init[100001];
int arr[100001];

int parent[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> init[i].first >> init[i].second;
        parent[i] = i;
    }

    map<int, int> m;
    for (int i = 1; i <= N; i++) {
        int v = abs(init[i].first) + abs(init[i].second);
        if (m.count(v)) parent[i] = m[v];
        else m[v] = i;
    }

    m[0] = 0;

    int M;
    cin >> M;
    while (M--) {
        int v;
        cin >> v;
        auto it = prev(m.upper_bound(v));
        v = it->first;
        if (v == 0) continue;
        int x = it->second;
        m.erase(it);
        if (m.count(v - 1)) {
            parent[x] = m[v - 1];
        }
        else m[v - 1] = x;
    }

    for (auto [v, x] : m) {
        arr[x] = v;
    }

    for (int i = 1; i <= N; i++) {
        arr[i] = arr[findp(i)];
    }

    for (int i = 1; i <= N; i++) {
        auto [x, y] = init[i];
        int d = abs(x) + abs(y) - arr[i];
        if (x != 0) {
            int sign = x / abs(x);
            x = abs(x);
            int dx = min(x, d);
            x -= dx; d -= dx;
            x *= sign;
        }
        if (y != 0) {
            int sign = y / abs(y);
            y = abs(y);
            y -= d; y *= sign;
        }
        cout << x << " " << y << endl;
    }


    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}