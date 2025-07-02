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
#define INF ll(4e18)
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
///////////////////////////////////////////////////////////////


unordered_set<ll> st;

void solve(int tc) {

    int N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        char x;
        cin >> x;
        a[i] = x - '0';
    }
    for (int i = 0; i < N; i++) {
        char x;
        cin >> x;
        b[i] = x - '0';
    }

    ll p = 1e9 + 7;
    ll powp = 1;

    ll hashval = 0;
    for (int i = 0; i < K; i++) {
        powp *= p;
        hashval *= p;
        hashval += a[i];
    }

    st.insert(hashval);
    for (int i = K; i < N; i++) {
        hashval *= p;
        hashval -= a[i - K] * powp;
        hashval += a[i];
        st.insert(hashval);
    }

    int ans = 0;

    hashval = 0;
    for (int i = 0; i < K; i++) {
        hashval *= p;
        hashval += b[i];
    }

    if (st.count(hashval)) {
        ans += 1;
        st.erase(hashval);
    }

    for (int i = K; i < N; i++) {
        hashval *= p;
        hashval -= b[i - K] * powp;
        hashval += b[i];
        if (st.count(hashval)) {
            ans += 1;
            st.erase(hashval);
        }
    }

    cout << ans;


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