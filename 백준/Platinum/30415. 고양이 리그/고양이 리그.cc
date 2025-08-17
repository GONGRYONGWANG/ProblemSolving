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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

bool isnprime[1000000];

int N, M;

vector<int> v;
ll DP[8][(1 << 7)];
ll dp(int x, int bit) {
    if (x == 0) {
        if (bit == 0) return 0;
        else return INF;
    }
    if (bit == 0) return INF;
    if (DP[x][bit]) return DP[x][bit];

    DP[x][bit] = INF;

    for (int i = 1; i < (1 << v.size()); i++) {
        if ((bit | i) != bit) continue;
        ll tmp = N;
        for (int j = 0; j < v.size(); j++) {
            if (i & (1 << j)) tmp /= v[j];
        }
        tmp += dp(x - 1, bit - i);
        DP[x][bit] = min(DP[x][bit], tmp);
    }

    return DP[x][bit];
}

void solve(int tc) {

    cin >> N >> M;
    // M<=7

    for (ll i = 2; i < N; i++) {
        if (isnprime[i]) continue;
        if (N % i == 0) {
            v.push_back(N);
            while (v.back() % i == 0) v.back() /= i;
            v.back() = N / v.back();
        }
        for (ll j = i * i; j < N; j += i) {
            isnprime[j] = true;
        }
    }

    if (v.size() < M) {
        cout << -1;
        return;
    }

    int bit = (1 << v.size()) - 1;
    for (int x = M; x > 0; x--) {

        ll mn = INF;
        ll ret = 0;
        for (int i = 1; i < (1 << v.size()); i++) {
            if ((bit | i) != bit) continue;
            ll tmp = N;
            for (int j = 0; j < v.size(); j++) {
                if (i & (1 << j)) tmp /= v[j];
            }
            tmp += dp(x - 1, bit - i);
            if (tmp < mn) {
                mn = tmp;
                ret = i;
            }
        }

        ll out = N;
        for (int j = 0; j < v.size(); j++) {
            if (ret & (1 << j)) out /= v[j];
        }

        cout << out << " ";
        bit -= ret;
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