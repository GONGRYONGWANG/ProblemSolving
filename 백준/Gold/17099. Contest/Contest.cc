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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


void solve(int tc) {

    int N;
    cin >> N;
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        e += 1;
        arr[i] = { s,e,c };
    }
    sort(arr.begin(), arr.end());

    map<int, int> m;
    m[0] = 0;
    for (int i = 0; i < N; i++) {
        int s, e, c;
        s = arr[i][0]; e = arr[i][1]; c = arr[i][2];
        auto it = m.upper_bound(s);
        it--;
        m[e] = max(m[e], it->second + c);
        it = m.find(e);
        while (1) {
            auto nit = it;
            nit++;
            if (nit == m.end()) break;
            if (nit->second > it->second) break;
            m.erase(nit);
        }
        auto prv = it;
        prv--;
        if (prv->second > it->second) m.erase(it);
    }

    cout << m.rbegin()->second;




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}