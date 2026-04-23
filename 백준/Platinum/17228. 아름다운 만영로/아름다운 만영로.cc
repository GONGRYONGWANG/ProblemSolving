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
using ll = long long;
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
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


vector<pii> E[500001];
int L;

ull p1 = 1e9 + 7; ull p2 = 998244353;
ull powp1, powp2;
ull hash1 = 0, hash2 = 0;

int ret = 0;
deque<int> q;
void dfs(int x, ull h1, ull h2) {
    
    int popd = -1;
    if (q.size() > L) {
        popd = q.front();
        h1 -= powp1 * popd;
        h2 -= powp2 * popd;
        q.pop_front();
    }

    if (h1 == hash1 && h2 == hash2) ret += 1;

    for (auto& [nx, w] : E[x]) {
        q.push_back(w);
        dfs(nx, h1 * p1 + w, h2 * p2 + w);
        q.pop_back();
    }

    if (popd != -1) q.push_front(popd);
}

void solve(int tc) {
    
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        E[u].push_back({ v,c - 'a' });
    }

    string P;
    cin >> P;
    L = P.length();
    powp1 = powp2 = 1;
    for (char x : P) {
        int d = x - 'a';
        hash1 = hash1 * p1 + d;
        hash2 = hash2 * p2 + d;
        powp1 *= p1; powp2 *= p2;
    }


    dfs(1, 0, 0);

    cout << ret;



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