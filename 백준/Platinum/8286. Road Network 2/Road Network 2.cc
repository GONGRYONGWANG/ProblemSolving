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

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second < b.second;
    }
};

void solve(int tc) {

    int N;
    cin >> N;

    pq<pii, vector<pii>, cmp> q;
    for (int i = 1; i <= N; i++) {
        int d; cin >> d;
        q.push({ i,d });
    }

    pq<pii, vector<pii>, cmp> q2;
    q2.push(q.top());
    q.pop();

    vector<pii> ret;
    while (!q.empty()) {
        if (q2.empty()) {
            cout << "BRAK";
            return;
        }

        auto [u, x] = q2.top();
        q2.pop();
        auto [v, y] = q.top();
        q.pop();
        if (x != 1) q2.push({ u,x - 1 });
        if (y != 1) q2.push({ v,y - 1 });
        ret.push_back({ u,v });
    }

    if (!q2.empty()) {
        cout << "BRAK";
        return;
    }

    for (auto [u, v] : ret) {
        cout << u << " " << v << endl;
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