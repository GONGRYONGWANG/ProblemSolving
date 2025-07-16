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

queue<pll> q[100000];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second < b.second;
    }
};

void solve(int tc) {

    ll X, K;
    cin >> X >> K;

    for (int i = 0; i < K; i++) {
        int l; cin >> l;
        pll p = { 0,0 };
        while (l--) {
            int x; cin >> x;
            p.second += x;
            p.first = min(p.first, p.second);
            if (p.second >= 0) {
                q[i].push(p);
                p = { 0,0 };
            }
        }
    }

    pq<pll, vector<pll>, cmp> PQ;
    for (int i = 0; i < K; i++) {
        if (!q[i].empty()) PQ.push({ i,q[i].front().first });
    }


    while (!PQ.empty() && X + PQ.top().second >= 0) {
        int idx = PQ.top().first;
        PQ.pop();
        X += q[idx].front().second;
        q[idx].pop();
        if (!q[idx].empty()) PQ.push({ idx,q[idx].front().first });
    }

    cout << X;





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