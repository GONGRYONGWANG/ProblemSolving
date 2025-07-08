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
struct PllHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pll& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
///////////////////////////////////////////////////////////////

string S[100];
vector<int> arr[100];

void solve(int tc) {

    int N;
    cin >> N;

    int l = 0;
    int r = 10000;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        r = min(r, int(S[i].length()));

        for (char x : S[i]) {
            if (x == 'A') arr[i].push_back(0);
            else if (x == 'C') arr[i].push_back(1);
            else if (x == 'G') arr[i].push_back(2);
            else arr[i].push_back(3);
        }
    }

    ll mod = 2e9 + 11;

    while (l < r) {
        int m = (l + r + 1) / 2;
        unordered_set<ll> st;

        vector<int> v = arr[0];
        ll ret = 0;
        ll pow4 = 1;
        for (int i = 0; i < m; i++) {
            pow4 *= 4;
            pow4 %= mod;
            ret *= 4;
            ret += v[i];
            ret %= mod;
        }

        st.insert(ret);

        for (int i = m; i < v.size(); i++) {
            ret *= 4;
            ret -= pow4 * v[i - m] % mod;
            ret += v[i];
            ret = (ret % mod + mod) % mod;
            st.insert(ret);
        }

        for (int j = 1; j < N; j++) {
            unordered_set<ll> nx;
            v = arr[j];
            ret = 0;
            for (int i = 0; i < m; i++) {
                ret *= 4;
                ret += v[i];
                ret %= mod;
            }
            if (st.count(ret)) nx.insert(ret);

            for (int i = m; i < v.size(); i++) {
                ret *= 4;
                ret -= pow4 * v[i - m];
                ret += v[i];
                ret = (ret % mod + mod) % mod;
                if (st.count(ret)) nx.insert(ret);
            }
            st = nx;
        }


        if (!st.empty()) l = m;
        else r = m - 1;

    }

    if (l == 0) {
        cout << "";
        return;
    }

    unordered_set<ll> st;

    vector<int> v = arr[0];
    ll ret = 0;
    ll pow4 = 1;
    for (int i = 0; i < l; i++) {
        pow4 *= 4;
        pow4 %= mod;
        ret *= 4;
        ret += v[i];
        ret %= mod;
    }

    st.insert(ret);

    for (int i = l; i < v.size(); i++) {
        ret *= 4;
        ret -= pow4 * v[i - l] % mod;
        ret += v[i];
        ret = (ret % mod + mod) % mod;
        st.insert(ret);
    }

    for (int j = 1; j < N; j++) {
        unordered_set<ll> nx;
        v = arr[j];
        ret = 0;
        for (int i = 0; i < l; i++) {
            ret *= 4;
            ret += v[i];
            ret %= mod;
        }
        if (st.count(ret)) nx.insert(ret);

        for (int i = l; i < v.size(); i++) {
            ret *= 4;
            ret -= pow4 * v[i - l];
            ret += v[i];
            ret = (ret % mod + mod) % mod;
            if (st.count(ret)) nx.insert(ret);
        }
        st = nx;
    }

    v = arr[0];

    ret = 0;
    for (int i = 0; i < l; i++) {
        ret *= 4;
        ret += v[i];
        ret %= mod;
    }

    if (st.count(ret)) {
        for (int j = 0; j < l; j++) cout << S[0][j];
        return;
    }

    for (int i = l; i < v.size(); i++) {
        ret *= 4;
        ret -= pow4 * v[i - l] % mod;
        ret += v[i];
        ret = (ret % mod + mod) % mod;
        if (st.count(ret)) {
            for (int j = i - l + 1; j <= i; j++) {
                cout << S[0][j];
            }
            return;
        }
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