// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
#define INF ll(4e18)
const int inf = 1e9 + 7;
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
vector<ll> manacher_preprocess(const vector<ll>& seq) { // 수열용 매내처 선행작업
    vector<ll> ret;
    ret.push_back(-1); // Sentinel value to simulate '#'
    for (ll x : seq) {
        ret.push_back(x);
        ret.push_back(-1); // Sentinel value between elements
    }
    return ret;
}

vector<ll> manacher(const vector<ll>& seq) { // 수열용 매내처
    int N = seq.size();
    vector<ll> ret(N, 0);
    ll r = 0, p = 0;
    for (ll i = 0; i < N; i++) {
        if (i <= r) ret[i] = min(ret[2 * p - i], r - i);
        else ret[i] = 0;

        while (i - ret[i] - 1 >= 0 && i + ret[i] + 1 < N && seq[i - ret[i] - 1] == seq[i + ret[i] + 1]) {
            ret[i] += 1;
        }

        if (r < i + ret[i]) {
            r = i + ret[i];
            p = i;
        }
    }
    return ret;
}
///////////////////////////////////////////////////////////////



ll hashval[3000][3001];
ll powp[3001];

void solve(int tc) {

    ll p = 1e9 + 7;

    int N;
    cin >> N;
    string s;
    cin >> s;

    powp[0] = 1;
    for (int i = 1; i <= N; i++) {
        powp[i] = powp[i - 1] * p;
    }

    for (int k = 1; k <= N; k++) {
        ll ret = 0;
        for (int i = 0; i < k; i++) {
            ret *= p;
            ret += s[i];
        }

        hashval[0][k] = ret;
        for (int i = k; i < N; i++) {
            ret -= s[i - k] * powp[k - 1];
            ret *= p;
            ret += ll(s[i]);
            hashval[i - k + 1][k] = ret;
        }

        ll ans = 0;

        for (int s = 0; s < k && s + k - 1 < N; s++) {
            vector<ll> v;
            for (int i = s; i + k - 1 < N; i += k) {
                v.push_back(hashval[i][k]);
            }
            vector<ll> mp = manacher_preprocess(v);
            vector<ll> mm = manacher(mp);
            for (ll x : mm) {
                ans += (x + 1) / 2;
            }
        }

        cout << ans << endl;

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