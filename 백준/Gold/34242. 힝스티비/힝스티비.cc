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


int cal(string& s) {
    if (s.length() < 3) return 0;
    int ret = 0;
    for (int i = 1; i < s.length()-1; i++) {
        if (s[i] != '^') continue;
        if (s[i - 1] == '+' && s[i + 1] == '+') ret += 1;
        else if (s[i - 1] == '-' && s[i + 1] == '-') ret -= 1;
    }
    return ret;
}

void solve(int tc) {

    string s;
    cin >> s;
    if (s.length() < 3) {
        cout << 0;
        return;
    }

    int total = 0;
    int N = s.length();
    for (int i = 1; i < N - 1; i++) {
        if (s[i] != '^') continue;
        if (s[i - 1] == '+' && s[i + 1] == '+') total += 1;
        else if (s[i - 1] == '-' && s[i + 1] == '-') total -= 1;
    }

    int ans = total;
    for (int i = 0; i < N; i++) {
        string tmp1;
        string tmp2;
        for (int j = i - 2; j <= i + 2; j++) {
            if (j < 0 || j >= N) continue;
            tmp1 += s[j];
            if (j == i) continue;
            tmp2 += s[j];
        }

        ans = max(ans, total - cal(tmp1) + cal(tmp2));

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