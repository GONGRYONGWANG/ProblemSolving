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

int init[500001];
int tree[2000000];
vector<int> ret;
void makeTree(int node, int start, int end) {
    tree[node] = -1;
    if (start == end) {
        tree[node] = init[start];
        return;
    }
    int mid = (start + end) / 2;
    makeTree(node * 2, start, mid);
    makeTree(node * 2 + 1, mid + 1, end);
}

void lazyProp(int node, int start, int end) {
    if (start == end || tree[node] == -1) return;
    tree[node * 2] = tree[node * 2 + 1] = tree[node];
    tree[node] = -1;
}

void update(int node, int start, int end, int left, int right, int val) {
    lazyProp(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        tree[node] = val;
        lazyProp(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
}

void get(int node, int start, int end, int idx) {
    lazyProp(node, start, end);
    if (idx > end || idx < start) return;
    if (start == end) {
        ret.push_back(tree[node]);
        return;
    }
    int mid = (start + end) / 2;
    get(node * 2, start, mid, idx);
    get(node * 2 + 1, mid + 1, end, idx);
}

void solve(int tc) {


    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    deque<pii> dq;
    for (int i = 1; i <= min(N, M); i++) {
        cin >> init[i];
    }
    for (int i = min(N, M) + 1; i <= N; i++) {
        int x;
        cin >> x;
        dq.push_back({ x,1 });
    }

    makeTree(1, 1, M);

    while (Q--) {

        int o;
        cin >> o;
        if (o == 1) {
            int l, r;
            cin >> l >> r;
            while (l <= r) {
                if (dq.empty()) {
                    update(1, 1, M, l, r, 0);
                    break;
                }

                auto [x, n] = dq.front();
                if (n > r - l + 1) {
                    update(1, 1, M, l, r, x);
                    dq.front().second -= r - l + 1;
                    break;
                }
                else {
                    update(1, 1, M, l, l + n - 1, x);
                    dq.pop_front();
                    l += n;
                }
            }
        }
        else if (o == 2) {
            int i;
            cin >> i;
            get(1, 1, M, i);
        }
        else if (o == 3) {
            int p, q;
            cin >> p >> q;
            dq.push_back({ p,q });

        }
        else {
            ll t;
            cin >> t;
            while (t) {
                if (dq.front().second > t) {
                    dq.front().second -= t;
                    break;
                }
                else {
                    t -= dq.front().second;
                    dq.pop_front();
                }
            }
        }
    }

    for (int x : ret) cout << x << " ";
    ret.clear();
    cout << endl;
    for (int i = 1; i <= M; i++) get(1, 1, M, i);
    for (int x : ret) cout << x << " ";


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