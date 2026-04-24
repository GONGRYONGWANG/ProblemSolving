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

ull p1 = 1e9 + 7; ull p2 = 998244353;

pair<ull, ull> psum[3000000];
ull pp1[3000001];
ull pp2[3000001];

void solve(int tc) {
    
    int N;
    cin >> N;

    set<vector<ull>> arr;
    for (int i = 0; i < N; i++) {
        string p;
        cin >> p;
        ull h1 = 0; ull h2 = 0;
        for (char& x : p) {
            h1 = h1 * p1 + (x - 'a');
            h2 = h2 * p2 + (x - 'a');
        }
        arr.insert({ p.length(),h1,h2 });
    }

    string s;
    cin >> s;

    vector<int> pre, suf;
    
    int L = s.length();

    pp1[0] = pp2[0] = 1;
    ull h1 = 0; ull h2 = 0;
    for (int i = 0; i < L; i++) {
        h1 = h1 * p1 + (s[i] - 'a');
        h2 = h2 * p2 + (s[i] - 'a');
        psum[i] = { h1,h2 };
        pp1[i + 1] = pp1[i] * p1;
        pp2[i + 1] = pp2[i] * p2;
    }

    for (int i = 0; i < L; i++) {
        if (arr.count({ ull(i + 1),psum[i].first,psum[i].second })) pre.push_back(i);
    }
    for (int i = L - 1; i >= 0; i--) {
        h1 = psum[L - 1].first;
        h2 = psum[L - 1].second;
        if (i != 0) {
            h1 -= psum[i - 1].first * pp1[L - i];
            h2 -= psum[i - 1].second * pp2[L - i];
        }
        if (arr.count({ ull(L - i), h1, h2 })) suf.push_back(i);
    }

    int ret = 0;
    for (int a : pre) {
        for (int b : suf) {
            if (a >= b) continue;
            h1 = psum[b - 1].first - psum[a].first * pp1[b - 1 - a];
            h2 = psum[b - 1].second - psum[a].second * pp2[b - 1 - a];
            if (arr.count({ ull(b - a - 1),h1,h2 })) ret += 1;
        }
    }

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