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

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = { y,x,i + 1 };
    }

    sort(arr.begin(), arr.end());

    map<int, int> L; L[-inf] = 0;
    map<int, int> R; R[inf] = 0;

    vector<int> ret(N + 1);

    for (int i = 0; i < N; i++) {
        int x = arr[i][1]; int y = arr[i][0]; int idx = arr[i][2];
        int l = x - y; int r = x + y;
        
        ret[idx] = max(prev(L.upper_bound(l))->second, R.lower_bound(r)->second) + 1;

        L[l] = ret[idx];
        auto it = L.find(l);
        while (next(it) != L.end() && next(it)->second <= it->second) L.erase(next(it));

        R[r] = ret[idx];
        it = R.find(r);
        while (it != R.begin() && prev(it)->second <= it->second) R.erase(prev(it));

    }

    while (Q--) {
        int q; cin >> q;
        cout << ret[q] << endl;
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