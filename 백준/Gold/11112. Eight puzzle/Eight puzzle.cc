// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
#define INF 1e18+7
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


int pow_10[10];

void solve(int tc) {

    

    
    pow_10[0] = 1;
    for (int i = 1; i < 10; i++) {
        pow_10[i] = pow_10[i - 1] * 10;
    }

    int s = 123456780;

    unordered_map<int, int> m;
    m[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int idx = 0;
        for (int i = 0; i < 9; i++) {
            if (x / pow_10[i] % 10 == 0) idx = i;
        }

        if (idx % 3 != 0) {
            int nx = x + (x % pow_10[idx] - x % pow_10[idx - 1]) * 9;
            if (!m.count(nx)) {
                m[nx] = m[x] + 1;
                q.push(nx);
            }
        }

        if (idx % 3 != 2) {
            int nx = x - (x % pow_10[idx + 2] - x % pow_10[idx + 1]) / 10 * 9;
            if (!m.count(nx)) {
                m[nx] = m[x] + 1;
                q.push(nx);
            }
        }

        if (idx / 3 != 0) {
            int nx = x + (x % pow_10[idx - 2] - x % pow_10[idx - 3]) * 999;
            if (!m.count(nx)) {
                m[nx] = m[x] + 1;
                q.push(nx);
            }
        }

        if (idx / 3 != 2) {
            int nx = x - (x % pow_10[idx + 4] - x % pow_10[idx + 3]) / 1000 * 999;
            if (!m.count(nx)) {
                m[nx] = m[x] + 1;
                q.push(nx);
            }
        }

    }

    int T;
    cin >> T;
    while (T--) {
        int x = 0;
        for (int i = 0; i < 9; i++) {
            char c;
            cin >> c;
            x *= 10;
            if (c != '#') x += c - '0';
        }

        if (m.count(x)) cout << m[x];
        else cout << "impossible";
        cout << endl;
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