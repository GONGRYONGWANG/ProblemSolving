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
//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

bool online(pll a, pll b, pll c) {
    if ((a.second - b.second) * (a.first - c.first) != (a.first - b.first) * (a.second - c.second)) return false;
    if ((a.second - b.second) * (c.first - a.first) + a.second * (a.first - b.first) != c.second * (a.first - b.first)) return false;
    return true;
}


void solve(int tc) {

    int N;
    cin >> N;
    vector<pll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    if (N <= 4) {
        cout << "success";
        return;
    }

    int idx = 0;
    for (int i = 2; i < N; i++) {
        if (!online(arr[0], arr[1], arr[i])) {
            idx = i;
            break;
        }
    }


    if (idx == 0) {
        cout << "success";
        return;
    }

    int idx2 = 0;
    for (int i = 2; i < N; i++) {
        if (i == idx) continue;
        if (!online(arr[0], arr[1], arr[i])) idx2 = i;
    }

    if (idx2 == 0) {
        cout << "success";
        return;
    }

    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (!online(arr[0], arr[1], arr[i]) && !online(arr[idx], arr[idx2], arr[i])) {
            flag = false;
        }
    }

    if (flag) {
        cout << "success";
        return;
    }

    swap(arr[0], arr[idx]);

    idx2 = 0;
    for (int i = 2; i < N; i++) {
        if (i == idx) continue;
        if (!online(arr[0], arr[1], arr[i])) idx2 = i;
    }

    if (idx2 == 0) {
        cout << "success";
        return;
    }

    flag = true;
    for (int i = 0; i < N; i++) {
        if (!online(arr[0], arr[1], arr[i]) && !online(arr[idx], arr[idx2], arr[i])) {
            flag = false;
        }
    }

    if (flag) {
        cout << "success";
        return;
    }

    swap(arr[1], arr[idx]);

    idx2 = 0;
    for (int i = 2; i < N; i++) {
        if (i == idx) continue;
        if (!online(arr[0], arr[1], arr[i])) idx2 = i;
    }

    if (idx2 == 0) {
        cout << "success";
        return;
    }

    flag = true;
    for (int i = 0; i < N; i++) {
        if (!online(arr[0], arr[1], arr[i]) && !online(arr[idx], arr[idx2], arr[i])) {
            flag = false;
        }
    }

    if (flag) {
        cout << "success";
        return;
    }

    cout << "failure";

    //cout << "Case #" << tc << ": " << debug << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}