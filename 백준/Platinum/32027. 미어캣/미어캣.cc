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
#define INF ll(4e18)
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

int N;
vector<int> L;
vector<int> R;
vector<int> lidx;
vector<int> ridx;

bool cal(int x, int y) {
    vector<int> arr(N);
    for (int i = 0; i < x; i++) {
        int idx = lidx[i];
        arr[idx] = L[L.size() - x + i];
    }
    for (int i = x; i < L.size(); i++) {
        int idx = lidx[i];
        arr[idx] = L[L.size() - i - 1];
    }
    for (int i = 0; i < R.size() - y; i++) {
        int idx = ridx[i];
        arr[idx] = R[i];
    }
    for (int i = R.size() - y; i < R.size(); i++) {
        int idx = ridx[i];
        arr[idx] = R[R.size() - 1 + R.size() - y - i];
    }

    vector<int> mx1(N);
    mx1[0] = arr[0];
    for (int i = 1; i < N; i++) mx1[i] = max(mx1[i - 1], arr[i]);

    for (int i = 0; i < x; i++) {
        int idx = lidx[i];
        if (mx1[idx] != arr[idx]) return false;
    }

    vector<int> mx2(N);
    mx2[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; i--) mx2[i] = max(mx2[i + 1], arr[i]);

    for (int i = R.size() - y; i < R.size(); i++) {
        int idx = ridx[i];
        if (mx2[idx] != arr[idx]) return false;
    }

    return true;

}

void solve(int tc) {

    cin >> N;


    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        char D;
        cin >> D;
        if (D == 'L') {
            L.push_back(A);
            lidx.push_back(i);
        }
        else {
            R.push_back(A);
            ridx.push_back(i);
        }
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int ans = 0;

    for (int i = 0; i <= L.size(); i++) {
        if (!cal(i, 0)) break;

        int l = 0;
        int r = R.size();
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (cal(i, m)) l = m;
            else r = m - 1;
        }

        ans = max(ans, i + l);
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