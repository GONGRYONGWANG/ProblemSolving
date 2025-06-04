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

    int N, L, R;
    cin >> N >> L >> R;
    string s;
    cin >> s;
    vector<pii> arr;
    arr.push_back({ -1,0 });

    for (int i = 0; i < N; i++) {
        if (s[i] == 'N') arr.push_back({ i,0 });
        else if (s[i] == 'C') arr.push_back({ i,1 });
    }

    arr.push_back({ N,0 });

    ll ans = 0;

    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i].second == 0 && arr[i + 1].second == 1 && (arr[i + 1].first - arr[i].first) % 2 == 0 && s[(arr[i + 1].first + arr[i].first) / 2] == 'P') {
            int d = (arr[i + 1].first - arr[i].first) + 1;
            int l = arr[i].first - arr[i - 1].first - 1;
            int r = arr[i + 2].first - arr[i + 1].first - 1;

            for (int x = d; x <= d + l; x++) {
                ans += max(0, min(x + r, R) - max(x, L) + 1);
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