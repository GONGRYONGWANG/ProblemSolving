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


ll arr[300000];
ll bck[448];
ll total;
int sqrtN;

void get() {

    int n = -1;
    ll ret = 0;
    while (ret * 2 < total) {
        n += 1;
        ret += bck[n];
    }
    ret -= bck[n];
    int idx = n * sqrtN - 1;
    while (ret * 2 < total) {
        idx += 1;
        ret += arr[idx];
    }

    ll ans = 2 * ret - total;
    ret -= arr[idx];
    ans = min(ans, total - 2 * ret);
    cout << ans << endl;

}

void solve(int tc) {

    int N;
    cin >> N;
    sqrtN = sqrt(N);
    total = 0;
    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        bck[i / sqrtN] += arr[i];
        total += arr[i];
    }

    get();
    int K;
    cin >> K;
    while (K--) {
        ll x, val;
        cin >> x >> val;
        total += val - arr[x];
        bck[x / sqrtN] -= arr[x];
        arr[x] = val;
        bck[x / sqrtN] += arr[x];
        get();
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