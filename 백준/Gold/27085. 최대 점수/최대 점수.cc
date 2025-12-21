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



ll arr[200001];

void solve(int tc) {

    int N, s;
    cin >> N >> s;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    queue<pll> A, B;

    ll total = 0, mn = 0;
    for (int i = s - 1; i >= 1; i--) {
        total += arr[i];
        mn = min(mn, total);
        if (total > 0) {
            A.push({ mn,total });
            total = mn = 0;
        }
    }

    total = 0; mn = 0;
    for (int i = s + 1; i <= N; i++) {
        total += arr[i];
        mn = min(mn, total);
        if (total > 0) {
            B.push({ mn,total });
            total = mn = 0;
        }
    }

    ll ret = 0;
    while (1) {
        if (!A.empty() && A.front().first + ret >= 0) {
            ret += A.front().second;
            A.pop();
        }
        else if (!B.empty() && B.front().first + ret >= 0) {
            ret += B.front().second;
            B.pop();
        }
        else break;
    }

    cout << ret;












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