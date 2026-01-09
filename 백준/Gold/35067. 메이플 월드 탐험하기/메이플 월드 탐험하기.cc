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


int arr[500001];
vector<pii> E[500001];

pii parent[500001][2];

pii findp(pii node) {
    auto [x, b] = node;
    if (parent[x][b] == node) return node;
    return parent[x][b] = findp(parent[x][b]);
}

void solve(int tc) {


    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back({ arr[v],v });
        E[v].push_back({ arr[u],u });
    }

    for (int i = 1; i <= N; i++) {
        sort(E[i].rbegin(), E[i].rend());
    }

    for (int i = 1; i <= N; i++) {
        int mxidx = E[i].front().second;
        if (E[mxidx].front().second == i) parent[i][0] = { mxidx,1 };
        else parent[i][0] = { mxidx,0 };

        if (E[i].size() == 1) {
            parent[i][1] = { i,1 };
            continue;
        }
        
        mxidx = E[i][1].second;
        if (E[mxidx].front().second == i) parent[i][1] = { mxidx,1 };
        else parent[i][1] = { mxidx,0 };

    }

    for (int i = 1; i <= N; i++) {
        cout << findp({ i, 0 }).first << endl;
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