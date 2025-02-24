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
const ll INF = 1e18 + 7;
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


ll D[200001];
vector<vector<ll>> E[200001];
bool visited[200001];

void solve(int tc) {
    
    int N, M;
    cin >> N >> M;
    vector<pll> arr;
    D[1] = 0;
    arr.push_back({ 0,1 });
    for (int i = 2; i <= N; i++) {
        cin >> D[i];
        arr.push_back({ D[i],i });
    }
    sort(arr.begin(), arr.end());

    while (M--) {
        ll u, v, l, r;
        cin >> u >> v >> l >> r;
        E[u].push_back({ v,l,r });
        E[v].push_back({ u,l,r });
    }


    ll ans = 1;
    ll mod = 1e9 + 7;

    visited[1] = true;

    for (int i = 1; i < N; i++) {
        int x = arr[i].second;
        visited[x] = true;


        ll ret1 = 1;
        ll ret2 = 1;

        bool b = false;
        for (vector<ll>& e : E[x]) {
            int nx = e[0];
            ll l = e[1]; ll r = e[2];
            if (!visited[nx]) continue;
            

            if (D[nx] + r < D[x]) {
                cout << 0;
                return;
            }

            if (D[nx] + l < D[x]) {
                l = D[x] - D[nx];
            }
            
            if (l > r) {
                cout << 0;
                return;
            }

            ret1 *= r - l + 1;

            if (D[x] < D[nx] + l) {
                ret2 *= r - l + 1; 
            }
            else {
                ret2 *= r - l; 
                b = true;
            }
            ret1 %= mod; ret2 %= mod;
        }

        if (!b) {
            cout << 0;
            return;
        }
        ans *= (ret1 + mod - ret2) % mod;
        ans %= mod;
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