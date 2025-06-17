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

    string A, B, C;
    cin >> A >> B >> C;

    int N = A.length();

    vector<int> a, b, c, d;

    string ret = A;

    for (int i = 0; i < N; i++) {
        if (A[i] == B[i] && A[i] == C[i]) continue;
        else if (A[i] == B[i]) c.push_back(i);
        else if (B[i] == C[i]) a.push_back(i);
        else if (A[i] == C[i]) b.push_back(i);
        else d.push_back(i);
    }

    for (int idx : a) ret[idx] = B[idx];

    int cnta = a.size(), cntb = b.size(), cntc = c.size();


    for (int idx : d) {
        if (cnta >= cntb && cnta >= cntc) {
            ret[idx] = A[idx];
            cntb += 1; cntc += 1;
        }
        else if (cntb >= cnta && cntb >= cntc) {
            ret[idx] = B[idx];
            cnta += 1; cntc += 1;
        }
        else {
            ret[idx] = C[idx];
            cnta += 1; cntb += 1;
        }
    }
    
    while (1) {
        if (cnta > cntb + 1 && cnta > cntc + 1 && !a.empty()) {
            ret[a.back()] = A[a.back()];
            cnta -= 1; cntb += 1; cntc += 1;
            a.pop_back();
        }
        else if (cntb > cnta + 1 && cntb > cntc + 1 && !b.empty()) {
            ret[b.back()] = B[b.back()];
            cntb -= 1; cnta += 1; cntc += 1;
            b.pop_back();
        }
        else if (cntc > cnta + 1 && cntc > cntb + 1 && !c.empty()) {
            ret[c.back()] = C[c.back()];
            cntc -= 1; cnta += 1; cntb += 1;
            c.pop_back();
        }
        else break;
    }

    cout << max(max(cnta, cntb), cntc) << endl << ret;



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