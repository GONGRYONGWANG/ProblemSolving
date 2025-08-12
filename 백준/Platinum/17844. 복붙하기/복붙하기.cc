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
struct PllHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pll& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
///////////////////////////////////////////////////////////////

 
void solve(int tc) {

    string s;
    cin >> s;

    int l = 0;
    int r = s.length();

    ll q = 31; ll q2 = 47;
    ll p = 1e9 + 9; ll p2 = 1e9 + 7;

    while (l < r) {
        int m = (l + r + 1) / 2;

        bool flag = false;
        unordered_map<pll, int, PllHasher> visit;

        ll hash = 0; ll hash2 = 0;
        ll powq = 1; ll powq2 = 1;
        for (int i = 0; i < m; i++) {
            hash *= q; hash += (s[i] - 'a');
            hash %= p;
            powq = powq * q % p;

            hash2 *= q2; hash2 += (s[i] - 'a');
            hash2 %= p2;
            powq2 = powq2 * q2 % p2;
        }

        visit[{hash, hash2}] = m - 1;
        for (int i = m; i < s.length(); i++) {
            hash *= q; hash += (s[i] - 'a');
            hash -= powq * (s[i - m] - 'a');
            hash %= p;
            hash = (hash + p) % p;

            hash2 *= q2; hash2 += (s[i] - 'a');
            hash2 -= powq2 * (s[i - m] - 'a');
            hash2 %= p2;
            hash2 = (hash2 + p2) % p2;


            if (visit.count({hash,hash2})) {
                if (i - visit[{hash,hash2}] >= m) {
                    flag = true;
                }
            }
            else {
                visit[{hash,hash2}] = i;
            }
        }
        
        if (flag) l = m;
        else r = m - 1;

    }

    if (l == 0) cout << -1;
    else cout << l;









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