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


int tree[50][100001];
int mod = 5000000;

void update(int k, int idx, int val) {
    for (; idx <= 100000; idx += idx & -idx) {
        tree[k][idx] += val; tree[k][idx] %= mod;
    }
}

int query(int k, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += tree[k][idx];
        sum %= mod;
    }
    return sum;
}


void solve(int tc) {

    int N, K;
    cin >> N >> K;

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
        }
        cout << N;
        return;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        update(1, x, 1);
        if (x == 1) continue;
        ans += query(K - 1, x - 1);
        ans %= mod;

        for (int k = 2; k < K; k++) {
            int val = query(k - 1, x - 1);
            update(k, x, val);
        }

    }

    cout << ans;
    


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