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


int N;
int arr[501];
int F[8];
int bt(int x) {
    if (x > N || x > 7) {
        int ret = 0;
        for (int j = 1; j <= N; j++) {
            if (arr[j] <= 0) continue;
            if (N >= 7) ret += 1;
            else ret += (arr[j] + F[N] - 1) / F[N];
        }
        return ret;
    }

    int ret = inf;

    if (x + N - 6 - 1 <= N) {
        for (int j = x; j < x + (N - 6); j++) {
            arr[j] -= 5000;
        }
        ret = min(ret, bt(x + 1) + 1);
        for (int j = x; j < x + (N - 6); j++) {
            arr[j] += 5000;
        }
    }

    for (int bit = 0; bit < (1 << (7 - x)); bit++) {
        int pc = 0;
        for (int i = 0; i < (7 - x); i++) {
            if (!(bit & (1 << i))) continue;
            pc += 1;
            int l = N - 5 + i;
            for (int j = x; j < x + l; j++) {
                arr[j] -= F[N + 1 - l];
            }
        }
        ret = min(ret, bt(x + 1) + pc);
        for (int i = 0; i < (7 - x); i++) {
            if (!(bit & (1 << i))) continue;
            int l = N - 5 + i;
            for (int j = x; j < x + l; j++) {
                arr[j] += F[N + 1 - l];
            }
        }
    }

    return ret;
}

void solve(int tc) {

    F[0] = 1;
    for (int i = 1; i <= 7; i++) F[i] = F[i - 1] * i;

    cin >> N;
    bool b = true;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        b &= (arr[i] == 1);
    }

    if (b) {
        cout << 1;
        return;
    }

    if (N >= 12) {
        cout << 2;
        return;
    }

    cout << bt(1);




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