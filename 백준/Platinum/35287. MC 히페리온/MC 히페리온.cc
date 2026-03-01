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

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

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

int idx[100001];

int R[100001];

int tree[400000];
void update(int node, int start, int end, int x) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node] = R[x];
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x); update(node * 2 + 1, mid + 1, end, x);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    vector<tuple<string, int>> arr(N);
    
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        arr[i] = { s,i + 1 };
    }

    sort(arr.begin(), arr.end());

    for (int j = 0; j < N; j++) {
        auto& [s, i] = arr[j];
        idx[i] = j + 1;
    }

    for (int i = 1; i <= N; i++) {
        cin >> R[idx[i]];
        update(1, 1, N, idx[i]);
    }

    vector<string> v(N);
    for (int j = 0; j < N; j++) {
        auto& [s, i] = arr[j];
        v[j] = s;
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, X;
            cin >> i >> X;
            R[idx[i]] = X;
            update(1, 1, N, idx[i]);
        }
        else {
            string L; cin >> L;
            reverse(L.begin(), L.end());
            string R = L;
            R.push_back('{');
            int l = lower_bound(v.begin(), v.end(), L) - v.begin() + 1;
            int r = upper_bound(v.begin(), v.end(), R) - v.begin() + 1;
            if (l == r) {
                cout << 0 << endl;
                continue;
            }
            cout << ll(get(1, 1, N, l, r - 1)) * L.length() << endl;
        }
    }



    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}