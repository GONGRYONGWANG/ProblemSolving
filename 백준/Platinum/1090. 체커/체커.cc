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


int ans[51];
pii arr[50];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    for (int k = 1; k <= N; k++) ans[k] = inf;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x = arr[i].first; int y = arr[j].second;
            vector<int> v;
            for (int k = 0; k < N; k++) {
                auto [a, b] = arr[k];
                v.push_back(abs(x - a) + abs(y - b));
            }
            sort(v.begin(), v.end());
            int ret = 0;
            for (int k = 0; k < N; k++) {
                ret += v[k];
                ans[k + 1] = min(ret, ans[k + 1]);
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        cout << ans[k] << " ";
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