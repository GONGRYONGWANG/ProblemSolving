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
#define INF 1e18+7
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
///////////////////////////////////////////////////////////////

bool isnprime[1000001];
vector<ll> prime;

void solve(int tc) {

    for (int i = 2; i <= 1000; i++) {
        if (isnprime[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j <= 1000000; j += i) {
            isnprime[j] = true;
        }
    }


    string a, b;
    cin >> a >> b;
    int N = a.length(); int M = b.length();

    ll mod = 1e9 + 7;
    unordered_map<ll, vector<pll>> m;
    
    for (int i = 0; i < N; i++) {
        ll h = 1;
        ll h2 = 1;
        for (int j = i; j < N; j++) {
            h *= prime[a[j] - 'a'];
            h %= mod;
            h2 *= prime[a[j] - 'a' + 26];
            h2 %= mod;
            m[h].push_back({ h2,j - i });
        }
    }

    int ans = 0;

    for (int i = 0; i < M; i++) {
        ll h = 1;
        ll h2 = 1;
        for (int j = i; j < M; j++) {
            h *= prime[b[j] - 'a'];
            h %= mod;
            h2 *= prime[b[j] - 'a' + 26];
            h2 %= mod;
            if (!m.count(h)) continue;
            for (pll& p : m[h]) {
                if (p == make_pair(h2, ll(j - i))) ans = max(ans, j - i + 1);
            }
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