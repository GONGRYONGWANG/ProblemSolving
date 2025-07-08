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
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
///////////////////////////////////////////////////////////////

string arr[10];

void solve(int tc) {

    int N;
    cin >> N;

    int l = 0;
    int r = inf;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        r = min(r, int(arr[i].length()));
    }

    ll p1 = 31;
    ll mod1 = 1e9 + 11;
    ll p2 = 37;
    ll mod2 = 1e9 + 7;

    while (l < r) {
        int m = (l + r + 1) / 2;

        unordered_set<pii, PiiHasher> st;
        string s = arr[0];

        ll ret1 = 0; ll ret2 = 0;
        ll powp1 = 1; ll powp2 = 1;

        for (int i = 0; i < m; i++) {
            powp1 = powp1 * p1 % mod1;
            powp2 = powp2 * p2 % mod2;

            ret1 *= p1;
            ret1 += ll(s[i] - 'a');
            ret1 %= mod1;

            ret2 *= p2;
            ret2 += ll(s[i] - 'a');
            ret2 %= mod2;
        }
        st.insert({ ret1,ret2 });
        for (int i = m; i < s.length(); i++) {
            ret1 *= p1;
            ret1 -= powp1 * ll(s[i - m] - 'a');
            ret1 += ll(s[i] - 'a');
            ret1 = (ret1 % mod1 + mod1) % mod1;

            ret2 *= p2;
            ret2 -= powp2 * ll(s[i - m] - 'a');
            ret2 += ll(s[i] - 'a');
            ret2 = (ret2 % mod2 + mod2) % mod2;

            st.insert({ ret1,ret2 });
        }

        for (int j = 1; j < N; j++) {

            unordered_set<pii, PiiHasher> nx;
            s = arr[j];
            ret1 = 0;
            ret2 = 0;

            for (int i = 0; i < m; i++) {
                ret1 *= p1;
                ret1 += ll(s[i] - 'a');
                ret1 %= mod1;

                ret2 *= p2;
                ret2 += ll(s[i] - 'a');
                ret2 %= mod2;
            }
            if (st.count({ ret1,ret2 })) nx.insert({ ret1,ret2 });
            for (int i = m; i < s.length(); i++) {
                ret1 *= p1;
                ret1 -= powp1 * ll(s[i - m] - 'a');
                ret1 += ll(s[i] - 'a');
                ret1 = (ret1 % mod1 + mod1) % mod1;

                ret2 *= p2;
                ret2 -= powp2 * ll(s[i - m] - 'a');
                ret2 += ll(s[i] - 'a');
                ret2 = (ret2 % mod2 + mod2) % mod2;

                if (st.count({ ret1,ret2 })) nx.insert({ ret1,ret2 });

            }
            st = nx;
        }

        if (!st.empty()) l = m;
        else r = m - 1;
    }

    cout << l;


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