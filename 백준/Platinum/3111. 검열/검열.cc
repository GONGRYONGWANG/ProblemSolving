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



void solve(int tc) {

    string A, T;
    cin >> A >> T;

    string rA = A;
    reverse(rA.begin(), rA.end());

    string l;
    string r;
    deque<char> m;

    for (char x : T) {
        m.push_back(x);
    }

    while (1) {
        bool flag = false;
        while (!m.empty() || !r.empty()) {
            if (m.empty()) {
                m.push_back(r.back());
                r.pop_back();
            }
            l.push_back(m.front());
            m.pop_front();
            if (l.size() < A.length()) continue;
            if (l.substr(l.size() - A.length()) == A) {
                int p = A.length();
                while (p--) l.pop_back();
                flag = true;
                break;
            }
            else continue;
        }
        if (!flag) break;

        flag = false;
        while (!m.empty() || !l.empty()) {
            if (m.empty()) {
                m.push_front(l.back());
                l.pop_back();
            }
            r.push_back(m.back());
            m.pop_back();
            if (r.size() < A.length()) continue;
            if (r.substr(r.size() - A.length()) == rA) {
                int p = A.length();
                while (p--) r.pop_back();
                flag = true;
                break;
            }
            else continue;
        }
        if (!flag) break;
    }

    for (char x : l) cout << x;

    reverse(r.begin(), r.end());
    for (char x : r) cout << x;



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