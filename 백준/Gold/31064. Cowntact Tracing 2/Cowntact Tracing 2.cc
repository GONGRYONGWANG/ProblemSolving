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
#define INF ll(9e18)
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

void solve(int tc) {

    int N;
    cin >> N;
    string s;
    cin >> s;

    int f = 0;
    int lidx = 0;
    while (lidx != N && s[lidx] == '1') {
        f += 1;
        lidx += 1;
    }

    if (lidx == N) {
        cout << 1;
        return;
    }

    int b = 0;
    int ridx = N - 1;
    while (ridx != -1 && s[ridx] == '1') {
        b += 1;
        ridx -= 1;
    }

    int t = inf;
    if (f != 0) t = min(t, f - 1);
    if (b != 0) t = min(t, b - 1);


    vector<int> arr;
    int ret = 0;
    for (int i = lidx; i <= ridx; i++) {
        if (s[i] == '1') {
            ret += 1;
        }
        else if (ret != 0) {
            arr.push_back(ret);
            t = min(t, (ret - 1) / 2);
            ret = 0;
        }
    }

    int ans = 0;
    if (f != 0) ans += (f + 2 * t) / (2 * t + 1);
    if (b != 0) ans += (b + 2 * t) / (2 * t + 1);

    for (int x : arr) {
        ans += (x + 2 * t) / (2 * t + 1);
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