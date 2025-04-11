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
#define INF ll(4e18+7)
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

map<ll, ll> m[100];

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    vector<pll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());


    for (int i = 0; i < N; i++) {
        m[i][arr[i].first] = 0;
        for (int j = i; j < N; j++) {
            auto [s, e] = arr[j];
            if (s > m[i].rbegin()->first) break;
            auto it = m[i].lower_bound(s);
            if (!m[i].count(e) || it->second + (e - s + 1) < m[i][e]) m[i][e] = it->second + (e - s + 1);
            else continue;

            it = m[i].find(e);
            if (next(it) != m[i].end() && next(it)->second <= it->second) {
                m[i].erase(it);
                continue;
            }
            while (it != m[i].begin() && prev(it)->second >= it->second) {
                m[i].erase(prev(it));
            }
        }


    }


    while (Q--) {
        ll l, r;
        cin >> l >> r;

        ll ret = INF;
        for (int i = 0; i < N && arr[i].first <= l; i++) {
            auto it = m[i].lower_bound(r);
            if (it != m[i].end()) ret = min(ret, it->second);
        }

        if (ret == INF) cout << -1;
        else cout << ret;
        cout << endl;

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