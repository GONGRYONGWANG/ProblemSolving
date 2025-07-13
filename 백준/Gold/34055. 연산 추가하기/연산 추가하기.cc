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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

void solve(int tc) {

    int N, H;
    cin >> N >> H;

    map<int, int> m;
    while (N--) {
        int a, b;
        cin >> a >> b;
        m[a] = max(m[a], b);
        auto it = m.find(a);
        if (it != m.begin() && prev(it)->second >= a) {
            it--;
            it->second = max(it->second, next(it)->second);
            m.erase(next(it));
        }
        while (next(it) != m.end() && it->second >= next(it)->first) {
            it->second = max(it->second, next(it)->second);
            m.erase(next(it));
        }
    }

    int prv = 1;
    vector<int> arr;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->first - prv != 0) arr.push_back(it->first - prv);
        prv = it->second + 1;
    }
    arr.push_back(H - prv + 1);

    sort(arr.rbegin(), arr.rend());

    int Q;
    cin >> Q;
    vector<pii> query(Q);
    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        query[i] = { t,i };
    }

    sort(query.rbegin(), query.rend());

    int r = 0;
    int total = 0;

    vector<int> ret(Q);
    for (auto [t, idx] : query) {
        while (r != arr.size() && arr[r] >= t) {
            total += arr[r];
            r += 1;
        }
        ret[idx] = total - r * (t - 1);
    }

    for (int x : ret) cout << x << endl;







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