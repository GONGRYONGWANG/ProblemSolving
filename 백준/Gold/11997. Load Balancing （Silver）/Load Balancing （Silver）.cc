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



int get(int x , int y, vector<pii>& arr) {
    vector<int> cnt(4, 0);
    for (auto& [a, b] : arr) {
        cnt[2 * (a < x) + (b < y)] += 1;
    }

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        ret = max(ret, cnt[i]);
    }
    return ret;
}

void solve(int tc) {
    int N;
    cin >> N;

    vector<pii> arr(N);
    for (auto& [x, y] : arr) cin >> x >> y;

    int ret = inf;
    for (auto& [x, y] : arr) {
        int l = 1; int r = 500000;
        while (r - l >= 3) {
            int p = (l * 2 + r) / 3;
            int q = (l + r * 2) / 3;
            if (get(x, p * 2, arr) <= get(x, q * 2, arr)) r = q;
            else  l = p;
        }

        for (int m = l; m <= r; m++) {
            ret = min(ret, get(x, m * 2, arr));
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