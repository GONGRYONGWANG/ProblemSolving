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

    int total = 0;

    vector<tuple<int, int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        arr[i] = { x,y,w };
        total += w;
    }

    sort(arr.begin(), arr.end());

    int ans = inf;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            auto [x1, y1, w1] = arr[i]; auto [x2, y2, w2] = arr[j];
            vector<int> v;
            int sum = 0;
            if (x1 == x2) {
                for (auto [x, y, w] : arr) {
                    if (x < x1) sum += w;
                    else if (x == x1) v.push_back(w);
                }
            }
            else if (y1 == y2) {
                for (auto [x, y, w] : arr) {
                    if (y < y1) sum += w;
                    else if (y == y1) v.push_back(w);
                }
            }
            else {
                for (auto [x, y, w] : arr) {
                    if ((x - x1) * (y2 - y1) < (y - y1) * (x2 - x1)) sum += w;
                    else if ((x - x1) * (y2 - y1) == (y - y1) * (x2 - x1)) v.push_back(w);
                }
            }

            ans = min(ans, abs(total - sum - sum));
            for (int w : v) {
                sum += w;
                ans = min(ans, abs(total - sum - sum));
            }
        }
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