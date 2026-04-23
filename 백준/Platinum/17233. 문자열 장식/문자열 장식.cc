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

bool DP[500000][100];

void solve(int tc) {
    
    int N;
    cin >> N;

    vector<string> pattern(N);
    for (string& p : pattern) cin >> p >> p;

    int L; cin >> L;
    string S; cin >> S;

    for (int i = 0; i < N; i++) {

        string& p = pattern[i];
        int l = p.length();

        ull hash1 = 0; ull hash2 = 0;
        ull pp1 = 1; ull pp2 = 1;

        for (char& x : p) {
            hash1 = hash1 * p1 + (x - 'a');
            hash2 = hash2 * p2 + (x - 'a');
            pp1 *= p1; pp2 *= p2;
        }

        ull h1 = 0; ull h2 = 0;
        for (int j = 0; j < p.length(); j++) {
            h1 = h1 * p1 + (S[j] - 'a');
            h2 = h2 * p2 + (S[j] - 'a');
        }

        if (h1 == hash1 && h2 == hash2) DP[0][i] = true;

        for (int j = l; j < L; j++) {
            h1 = h1 * p1 + (S[j] - 'a') - pp1 * (S[j - l] - 'a');
            h2 = h2 * p2 + (S[j] - 'a') - pp2 * (S[j - l] - 'a');
            if (h1 == hash1 && h2 == hash2) DP[j - l + 1][i] = true;
        }
    }

    int ret = inf;
    vector<int> cnt(100, 0);
    int count = 0;
    int s = 0; int e = -1;
    while (1) {
        while (count != N) {
            e += 1;
            if (e == L) break;
            for (int i = 0; i < N; i++) {
                int l = pattern[i].length();
                if (e - l + 1 < 0) continue;
                if (!DP[e - l + 1][i]) continue;
                cnt[i] += 1;
                if (cnt[i] == 1) count += 1;
            }
        }

        if (e == L) break;

        while (count == N) {
            ret = min(ret, e - s + 1);
            for (int i = 0; i < N; i++) {
                int l = pattern[i].length();
                if (!DP[s][i]) continue;
                cnt[i] -= 1;
                if (cnt[i] == 0) count -= 1;
            }
            s += 1;
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