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
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> ret(N, 1);

    if (N % 3 == 0) {
        for (int i = 0; i + 3 < N; i++) {
            ret[i + 3] = ret[i] + (arr[i + 1] - arr[i]);
        }

        vector<int> mn(3, inf);
        for (int i = 0; i < N; i++) {
            mn[i % 3] = min(mn[i % 3], ret[i]);
        }

        for (int i = 0; i < N; i++) {
            ret[i] += (1 - mn[i % 3]);
        }

        int x = arr[0] - (ret[0] + ret[1] + ret[2]);
        for (int i = 0; i < N; i += 3) {
            ret[i] += x;
        }
        for (int i = 1; i < N; i++) {
            cout << ret[i] << endl;
        }
        cout << ret[0];
        return;
    }

    int idx = 0;
    while (idx != N - 3) {
        ret[(idx + 3) % N] = ret[idx] + (arr[(idx + 1) % N] - arr[idx]);
        idx = (idx + 3) % N;
    }

    int x = arr[0] - (ret[0] + ret[1] + ret[2]);
    x /= 3;
    for (int i = 0; i < N; i++) {
        ret[i] += x;
    }
    for (int i = 1; i < N; i++) {
        cout << ret[i] << endl;
    }
    cout << ret[0];


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