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
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


void solve(int tc) {

    string A, B;
    cin >> A >> B;
    
    int N = A.length();
    for (int i = 0; i < N - 1; i++) B.push_back(B[i]);

    ull hash1 = 0;
    uint hash2 = 0;
    int p = 998244357;
    ull powp1 = 1; uint powp2 = 1;


    for (char x : A) {
        int d = (x - '0');
        hash1 *= p; hash1 += d;
        hash2 *= p; hash2 += d;
        powp1 *= p; powp2 *= p;
    }

    int ret = 0;

    ull h1 = 0; uint h2 = 0;
    for (int i = 0; i < N; i++) {
        int d = (B[i] - '0');
        h1 *= p; h1 += d;
        h2 *= p; h2 += d;
    }

    if (h1 == hash1 && h2 == hash2) ret += 1;

    for (int i = N; i < 2 * N - 1; i++) {
        int d = (B[i] - '0');
        h1 *= p; h1 += d;
        h2 *= p; h2 += d;
        
        d = (B[i - N] - '0');
        h1 -= powp1 * d;
        h2 -= powp2 * d;

        if (h1 == hash1 && h2 == hash2) ret += 1;
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