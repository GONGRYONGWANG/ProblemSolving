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
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

map<ll, vector<int>> m;
pll arr[250001];
ll W[250001];
set<pll> st;

void solve(int tc) {

    int N;
    cin >> N;
    

    st.insert({ 0,-1 });
    st.insert({ INF, -2 });

    for (int i = 1; i <= N; i++) {
        ll l, r, y; char c;
        cin >> l >> r >> y >> c;
        int t = (c == 'S');
        W[i] = r - l + 1;
        m[l].push_back(i);
        m[r + 1].push_back(-i);
        arr[i] = { y,t };
    }

    ll ret = 0;
    ll total = 0;
    ll cnt = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        vector<int> v = it->second;
        sort(v.begin(), v.end());
        for (int& x : v) {
            if (x > 0) {
                total += W[x];
                st.insert(arr[x]);
                auto xit = st.find(arr[x]);
                auto lit = prev(xit);
                auto rit = next(xit);
                cnt += (xit->second == lit->second) + (xit->second == rit->second) - (lit->second == rit->second);
            }
            else {
                x = -x;
                total -= W[x];
                auto xit = st.find(arr[x]);
                auto lit = prev(xit);
                auto rit = next(xit);
                cnt -= (xit->second == lit->second) + (xit->second == rit->second) - (lit->second == rit->second);
                st.erase(arr[x]);
            }
        }
        if (cnt == 0) ret = max(ret, total);
    }

    cout << ret;



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