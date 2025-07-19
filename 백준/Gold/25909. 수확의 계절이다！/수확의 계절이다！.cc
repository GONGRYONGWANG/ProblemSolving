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
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

///////////////////////////////////////////////////////////////
    




void solve(int tc) {


    int N, K;
    cin >> N >> K;

    int idx = 0;
    unordered_map<pii, int, PiiHasher> m;
    int x = 0; int y = 0;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        char a; int b; int dir;
        cin >> a >> b;
        if (a == 'N') dir = 0;
        else if (a == 'E') dir = 1;
        else if (a == 'S') dir = 2;
        else dir = 3;
        while (b--) {
            x += dx[dir]; y += dy[dir];
            if (!m.count({ x,y })) {
                m[{x, y}] = idx;
                idx++;
            }
            v.push_back(m[{x, y}]);
        }
    }

    int l = 0;
    int r = 1000000;
    while (l < r) {
        int m = (l + r + 1) / 2;
        int ret = 0;
        vector<int> T(idx, -1);
        for (int t = 0; t < v.size(); t++) {
            int pos = v[t];
            if (T[pos] == -1) T[pos] = t;
            else if (T[pos] + m <= t) {
                ret += 1;
                T[pos] = t;
            }
        }
        if (ret >= K) l = m;
        else r = m - 1;
    }

    if (l == 0) cout << -1;
    else cout << l;





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