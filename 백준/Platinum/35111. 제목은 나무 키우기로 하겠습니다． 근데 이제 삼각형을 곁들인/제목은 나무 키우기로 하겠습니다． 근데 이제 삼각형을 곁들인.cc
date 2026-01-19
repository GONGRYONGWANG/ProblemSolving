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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


// 45번째 피보나치 수는 1e9를 넘어감

multiset<int> st[100001];
bool satisfied[100001];
int parent[100001];

void solve(int tc) {

    int N;
    cin >> N;

    int ret = 0;

    int x; cin >> x;
    st[1].insert(x);
    for (int i = 2; i <= N; i++) {
        cin >> parent[i] >> x;

        int idx = i;
        while (idx != 0 && !satisfied[idx]) {
            st[idx].insert(x);

            auto it = st[idx].lower_bound(x);

            satisfied[idx] |= (it != st[idx].begin() && prev(it) != st[idx].begin() && *prev(prev(it)) + *prev(it) > *it);
            satisfied[idx] |= (it != st[idx].begin() && next(it) != st[idx].end() && *prev(it) + *it > *next(it));
            satisfied[idx] |= (next(it) != st[idx].end() && next(next(it)) != st[idx].end() && *it + *next(it) > *next(next(it)));

            if (satisfied[idx]) ret += 1;

            idx = parent[idx];

        }

        cout << ret << endl;

    }







    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}