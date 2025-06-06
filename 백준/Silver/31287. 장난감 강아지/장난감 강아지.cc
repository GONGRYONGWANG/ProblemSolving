// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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

    ll N, K;
    cin >> N >> K;

    vector<pll> arr(N + 1, { 0,0 });
    for (int i = 1; i <= N; i++) {
        char x;
        cin >> x;
        arr[i] = arr[i - 1];
        if (x == 'U')  arr[i].first += 1;
        else if (x == 'D') arr[i].first -= 1;
        else if (x == 'L') arr[i].second -= 1;
        else arr[i].second += 1;
    }

    int a = arr[N].first; int b = arr[N].second;

    if (a == 0 && b == 0) {
        cout << "YES";
        return;
    }

    for (int i = 1; i < N; i++) {
        auto [x, y] = arr[i];
        if (x == 0 && y == 0) {
            cout << "YES";
            return;
        }
        if ((x == 0) ^ (a == 0)) continue;
        if ((y == 0) ^ (b == 0)) continue;

        if (a != 0) {
            if (x % a) continue;
            if (x / a > 0) continue;
            if (-x / a >= K) continue;
        }

        if (b != 0) {
            if (y % b) continue;
            if (y / b > 0) continue;
            if (-y / b >= K) continue;
        }

        if (a != 0 && b != 0) {
            if (x / a != y / b) continue;
        }

        cout << "YES";
        return;

    }

    cout << "NO";



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