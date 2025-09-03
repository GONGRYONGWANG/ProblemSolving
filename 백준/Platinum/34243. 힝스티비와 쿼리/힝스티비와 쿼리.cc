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

int cal(string& sss) {
    if (sss.length() < 3) return 0;
    int ret = 0;
    for (int i = 1; i < sss.length() - 1; i++) {
        if (sss[i] != '^') continue;
        if (sss[i - 1] == '+' && sss[i + 1] == '+') ret += 1;
        else if (sss[i - 1] == '-' && sss[i + 1] == '-') ret -= 1;
    }
    return ret;
}

string s;
int cal(int l, int r) {
    string tmp;
    for (int i = l; i <= r; i++) {
        tmp.push_back(s[i]);
    }
    return cal(tmp);
}

int cal(int l, int r, int x) {
    string tmp;
    for (int i = l; i <= r; i++) {
        if (i == x) continue;
        tmp.push_back(s[i]);
    }
    return cal(tmp);
}

int psum[300000];
vector<int> arr[3];

void solve(int tc) {

    cin >> s;
    int N = s.length();

    for (int i = 2; i < N; i++) {
        psum[i] = psum[i - 1] + cal(i - 2, i);
    }

    for (int i = 0; i < N; i++) {
        int ret = cal(max(0, i - 2), min(N - 1, i + 2), i) - cal(max(0, i - 2), min(N - 1, i + 2));
        if (ret >= 1) arr[ret].push_back(i);
    }


    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l -= 1; r -= 1;

        if (r - l + 1 < 3) {
            cout << 0 << endl;
            continue;
        }

        int ret = psum[r] - psum[l + 1];

        int ext = 0;
        for (int i = l; i <= min(l + 1, r); i++) {
            ext = max(ext, cal(l, min(i + 2, r), i) - cal(l, min(i + 2, r)));
        }
        for (int i = r; i >= max(r - 1, l); i--) {
            ext = max(ext, cal(max(i - 2, l), r, i) - cal(max(i - 2, l), r));
        }

        auto it = lower_bound(arr[2].begin(), arr[2].end(), l + 2);
        if (it != arr[2].end() && *it <= r - 2) ext = max(ext, 2);
        it = lower_bound(arr[1].begin(), arr[1].end(), l + 2);
        if (it != arr[1].end() && *it <= r - 2) ext = max(ext, 1);

        cout << ret + ext << endl;
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