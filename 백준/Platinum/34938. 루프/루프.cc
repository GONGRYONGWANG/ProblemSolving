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

struct treeNode {
    int dx = 0, dy = 0, dd = 0;
    treeNode() = default;
    treeNode(int dx,int dy, int dd) : dx(dx), dy(dy), dd(dd) {}

};

treeNode mer(treeNode A, treeNode B) {
    treeNode ret = A;
    ret.dd += B.dd;
    ret.dd %= 4;
    if (A.dd == 0) {
        ret.dx += B.dx;
        ret.dy += B.dy;
    }
    else if (A.dd == 1) {
        ret.dy += B.dx;
        ret.dx -= B.dy;
    }
    else if (A.dd == 2) {
        ret.dx -= B.dx;
        ret.dy -= B.dy;
    }
    else {
        ret.dx += B.dy;
        ret.dy -= B.dx;
    }
    return ret;
}

treeNode tree[12000];
void update(int node, int start, int end, int x, char c) {
    if (x<start || x>end) return;
    if (start == end) {
        if (c == 'L') {
            tree[node] = { 0,0,3 };
        }
        else if (c == 'R') {
            tree[node] = { 0,0,1 };
        }
        else tree[node] = { 1,0,0 };
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, c);
    update(node * 2 + 1, mid + 1, end, x, c);
    tree[node] = mer(tree[node * 2], tree[node * 2 + 1]);
}



void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        char c; cin >> c;
        update(1, 1, N, i, c);
    }

    while (Q--) {
        int x; char c;
        cin >> x >> c;
        update(1, 1, N, x, c);
        if ((tree[1].dx != 0 || tree[1].dy != 0) && tree[1].dd == 0) cout << 1;
        else cout << 0;
        cout << endl;

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