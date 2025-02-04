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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<set<int>*> st(7);
ll arr[100000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int j = 0; j < 7; j++) st[j] = new set<int>;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        st[arr[i] % 7]->insert(i);
    }

    int ret = N;
    ll psum = 0;
    ll mod = 1e9 + 7;
    for (int i = 0; i < M; i++) {
        ll x;
        cin >> x;
        vector<set<int>*> nx(7);
        for (int j = 0; j < 7; j++) {
            nx[(j + x) % 7] = st[j];
        }
        if (nx[0]->size() == ret) continue;
        psum += x;
        psum %= mod;
        ret -= nx[0]->size();
        nx[0]->clear();
        st = nx;
    }

    cout << ret << endl;
    vector<int> v;
    for (int j = 0; j < 7; j++) {
        for (int x : *st[j]) {
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    for (int x : v) {
        cout << (arr[x] + psum) % mod << " ";
    }


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}