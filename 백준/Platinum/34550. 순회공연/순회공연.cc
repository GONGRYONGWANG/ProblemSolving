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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int nx[100001][18];

void solve(int tc) {


    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) cin >> nx[i][0];

    for (int j = 1; j <= 17; j++) {
        for (int i = 1; i <= N; i++) {
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
        }
    }

    vector<int> cnt(N + 1, 0);
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]] += 1;
    }

    bool flag = false;
    for (int i = 1; i <= N; i++) flag |= (cnt[i] >= K);
    if (flag) {
        cout << 1;
        return;
    }

    cnt.clear(); cnt.resize(N + 1, 0);
    for (int x : arr) cnt[nx[x][17]] += 1;

    flag = false;
    for (int i = 1; i <= N; i++) flag |= (cnt[i] >= K);

    if (!flag) {
        cout << -1;
        return;
    }

    int ret = 0;
    for (int j = 16; j >= 0; j--) {
        cnt.clear(); cnt.resize(N + 1, 0);
        for (int x : arr) cnt[nx[x][j]] += 1;
        flag = false;
        for (int i = 1; i <= N; i++) {
            flag |= (cnt[i] >= K);
        }
        if (flag) continue;

        for (int& x : arr) {
            x = nx[x][j];
        }
        ret |= (1 << j);
    }

    cout << ret + 2;




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