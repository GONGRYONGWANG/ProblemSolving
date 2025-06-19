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


int N;
int nx[400003][19];

ll arr[400002];

ll tree[1600004];

void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid); makeTree(node * 2 + 1, mid + 1, end);
    tree[node] = gcd(tree[node * 2], tree[node * 2 + 1]);
}

ll get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return gcd(get(node * 2, start, mid, left, right), get(node * 2 + 1, mid + 1, end, left, right));
}

int getnx(int x) {
    int idx = max(x, nx[x - 1][0] - 1);
    ll g = get(1, 1, 2 * N + 1, x, idx);
    while (g != 1) {
        idx += 1;
        g = gcd(g, arr[idx]);
    }
    return idx + 1;
}

void solve(int tc) {

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i + N] = arr[i];
    }

    arr[2 * N + 1] = 1;
    makeTree(1, 1, 2 * N + 1);

    for (int i = 1; i <= 2 * N; i++) {
        nx[i][0] = getnx(i);
    }

    nx[2 * N + 1][0] = 2 * N + 2;
    nx[2 * N + 2][0] = 2 * N + 2;

    for (int j = 1; j < 19; j++) {
        for (int i = 1; i <= 2 * N + 2; i++) {
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= N; i++) {

        int ret = 0;
        int x = i;
        for (int j = 18; j >= 0; j--) {
            if (nx[x][j] <= i + N) {
                ret += (1 << j);
                x = nx[x][j];
            }
        }

        cout << ret << endl;

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