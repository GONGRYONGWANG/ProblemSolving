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
    vector<pair<int,string>> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());

    int M;
    cin >> M;
    unordered_map<string, pii> name;
    while (M--) {
        string s; int t;
        cin >> s >> t;
        int mx1 = -1; int mx2 = -1;
        for (int i = 0; i < N; i++) {
            auto [d, x] = arr[i];
            if (mx1 == -1) {
                mx2 = mx1; mx1 = i;
                continue;
            }
            if (abs(t - d) < abs(t - arr[mx1].first)) {
                mx2 = mx1; mx1 = i;
                continue;
            }
            if (abs(t - d) == abs(t - arr[mx1].first) && x < arr[mx1].second) {
                mx2 = mx1; mx1 = i;
                continue;
            }
            if (mx2 == -1) {
                mx2 = i;
                continue;
            }
            if (abs(t - d) < abs(t - arr[mx2].first)) {
                mx2 = i;
                continue;
            }
            if (abs(t - d) == abs(t - arr[mx2].first) && x < arr[mx2].second) {
                mx2 = i;
                continue;
            }
        }
        name[s] = { mx2,mx1 };
    }



    int Q;
    cin >> Q;
    string cur;
    while (Q--) {
        string q1, q2, q3;
        cin >> q1 >> q2 >> q3;
        if (q3.back() == '!') {
            cur = q1;
            cout << "hai!" << endl;
        }
        else {
            auto [a, b] = name[cur];
            cout << arr[a].second << " yori mo " << arr[b].second << endl;
        }
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