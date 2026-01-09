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

vector<int> noE[200001];
bool visited[200001];
int level[200001];
ll DP[200001];
ll mod = 998244353;

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        noE[u].push_back(v);
        noE[v].push_back(u);
    }

    set<int> st;
    for (int i = 2; i <= N; i++) st.insert(i);

    visited[1] = true;
    level[1] = 0;
    DP[1] = 1;
    vector<int> v = { 1 };

    int lv = 0;

    while (!st.empty()) {

        lv += 1;
        set<int> noedge;
        for (int nx : noE[v.front()]) noedge.insert(nx);
        ll total = 0;

        for (int x : v) {
            total = (total + DP[x]) % mod;
            set<int> ne;
            for (int nx : noE[x]) {
                if (visited[nx]) continue;
                ne.insert(nx);
            }

            swap(noedge, ne);
            auto it = noedge.begin();
            while (it != noedge.end()) {
                it++;
                if (!ne.count(*prev(it))) {
                    noedge.erase(prev(it));
                }
            }
        }

        for (int x : noedge) {
            if (st.count(x)) st.erase(x);
        }

        for (int x : st) {
            DP[x] = total;
        }

        for (int x : v) {
            for (int nx : noE[x]) {
                if (st.count(nx)) {
                    DP[nx] = (DP[nx] + mod - DP[x]) % mod;
                }
            }
        }

        v.clear();
        for (int x : st) {
            v.push_back(x);
            visited[x] = true;
            level[x] = lv;
        }

        swap(noedge, st);

    }


    for (int i = 1; i <= N; i++) {
        cout << level[i] << " " << DP[i] << endl;
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