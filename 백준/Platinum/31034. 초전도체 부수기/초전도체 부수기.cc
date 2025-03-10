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
const ll INF = 1e18 + 7;
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

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.first > b.first;
    }
};

void solve(int tc) {

    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    pq<pll, vector<pll>, cmp> q;
    if (N == K) q.push({ 1,N });
    else {
        q.push({ 1,K - 1 });
        q.push({ N - K + 1,1 });
    }

    while (q.top().first != N) {
        auto [val, cnt] = q.top();
        q.pop();
        if (cnt >= 2) {
            ans += val * 2 * (cnt / 2);
            q.push({ val * 2,cnt / 2 });
            if (cnt % 2) q.push({ val,1 });
        }
        else {
            ans += val + q.top().first;
            q.push({ val + q.top().first,1 });
            val = q.top().first; cnt = q.top().second;
            q.pop();
            if (cnt != 1) q.push({ val, cnt - 1 });
        }
    }

    cout << ans << endl;



}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}