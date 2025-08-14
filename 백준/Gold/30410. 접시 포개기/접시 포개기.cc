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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


void solve(int tc) {


    int N;
    cin >> N;

    vector<pii> arr;
    arr.push_back({ 1,0 });
    arr.push_back({ 2,0 });
    while (N--) {
        int x; cin >> x;
        if (x == arr.back().first) arr.back().second += 1;
        else {
            if (arr.back().first == 1) {
                if (arr.back().second % 2) {
                    arr.push_back({ 2,1 });
                }
                else {
                    int sum = arr.back().second /= 2;
                    arr.pop_back();
                    if (arr.back().first == 2) arr.back().second += sum + 1;
                    else arr.push_back({ 2,sum + 1 });
                }
            }
            else {
                arr.push_back({ x,1 });
            }
        }
    }
    arr.push_back({ 1,0 });

    int ret = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].first != 2) continue;
        ret = max(ret, arr[i - 1].second / 2 + arr[i].second + arr[i + 1].second / 2);
    }

    if (ret == 0) cout << 1;
    else {
        int ans = 2;
        while (ret / 2) {
            ret /= 2;
            ans *= 2;
        }
        cout << ans;
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