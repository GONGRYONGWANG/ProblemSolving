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



map<int, int> m;
int nx[300000][19];

void solve(int tc) {
    
    int N;
    cin >> N;

    map<int, int> comp;

    vector<pii> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        int s, e;
        cin >> s >> e;
        arr[i] = { s,e };
        comp[s] = 0;
        comp[e] = 0;
    }

    int idx = 0;
    for (auto it = comp.begin(); it != comp.end(); it++) {
        it->second = idx;
        idx += 1;
    }

    for (int i = 1; i <= N; i++) {
        pii& p = arr[i];
        p.first = comp[p.first];
        p.second = comp[p.second];
        m[p.first] = max(m[p.first], p.second);
    }

    auto it = m.begin();
    while (next(it) != m.end()) {
        while (next(it) != m.end() && next(it)->second <= it->second) m.erase(next(it));
        it++;
    }

    m[-1] = 0;

    for (int i = 0; i < 300000; i++) {
        nx[i][0] = max(i, prev(m.upper_bound(i))->second);
    }

    for (int j = 1; j <= 18; j++) {
        for (int i = 0; i < 300000; i++) {
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        pii a = arr[A]; pii b = arr[B];
        if (a.first > b.first) swap(a, b);
        if (nx[a.second][18] < b.first) {
            cout << -1 << endl;
            continue;
        }

        if (a.second >= b.first) {
            cout << 1 << endl;
            continue;
        }

        int ret = 2;
        int x = a.second;
        for (int j = 17; j >= 0; j--) {
            if (nx[x][j] < b.first) {
                x = nx[x][j];
                ret += (1 << j);
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