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

    vector<int> arr;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        char x; cin >> x;
        if (x == '1') {
            arr.push_back(cnt);
            cnt = 0;
        }
        else cnt += 1;
    }
    if (cnt != 0) arr.push_back(cnt);

    if (arr.size() == 1) {
        cout << N - 1;
        return;
    }

    int l = 0;
    int r = N - 2;

    for (int i = 1; i < arr.size() - 1; i++) {
        r = min(r, arr[i]);
    }

    while (l < r) {
        int m = (l + r + 1) / 2;

        int ret = 0;
        ret += arr.front() / (m + 1);
        ret += arr.back() / (m + 1);
        for (int i = 1; i < arr.size() - 1; i++) {
            ret += (arr[i] - m) / (m + 1);
        }

        if (ret >= 2) l = m;
        else r = m - 1;

    }

    cout << l + 1;




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