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

vector<int> E[200001];
int ind[200001];
vector<int> fromA[200001];
vector<int> fromB[200001];
vector<int> to[200001];
bool isB[200001];

ll arr[200001];

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[v].push_back(u);
        ind[u] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (fromA[x].size() >= 450) {
            isB[x] = true;
            for (int a : fromA[x]) {
                to[a].push_back(x);
            }
            fromB[x].push_back(x);
            fromA[x].clear();
        }
        else fromA[x].push_back(x);


        for (int nx : E[x]) {
            for (int a : fromA[x]) {
                fromA[nx].push_back(a);
            }
            for (int b : fromB[x]) {
                fromB[nx].push_back(b);
            }
            ind[nx] -= 1;
            if (ind[nx] == 0) q.push(nx);
        }
    }

    int M, Q;
    cin >> M >> Q;
    int T = M + Q;
    while (T--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, x;
            cin >> u >> x;
            arr[u] += x;
            if(!isB[u]) {
                for (int b : to[u]) {
                    arr[b] += x;
                }
            }
        }
        else {
            int u;
            cin >> u;
            ll ret = 0;
            for (int a : fromA[u]) {
                ret += arr[a];
            }
            for (int b : fromB[u]) {
                ret += arr[b];
            }
            cout << ret << endl;
        }
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