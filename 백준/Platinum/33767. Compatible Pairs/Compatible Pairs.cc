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


unordered_map<ll, ll> m;

void solve(int tc) {
   
    ll N, A, B;
    cin >> N >> A >> B;

    for (int i = 0; i < N; i++) {
        ll n, d;
        cin >> n >> d;
        m[d] = n;
    }
     
    ll ret = 0;
    if (A == B) {
        if (A % 2 == 0 && m.count(A / 2)) {
            ret += m[A / 2] / 2;
            m.erase(A / 2);
        }
        while (!m.empty()) {
            auto [v, c] = *m.begin();
            m.erase(v);
            if (m.count(A - v)) {
                ret += min(c, m[A - v]);
                m.erase(A - v);
            }
        }
        cout << ret;
        return;
    }

    while (!m.empty()) {
        deque<pll> q;
        auto [v, c] = *m.begin();
        m.erase(v);
        q.push_back({ v,c });

        ll x = A - v;
        while (m.count(x)) {
            q.push_front({ x,m[x] });
            m.erase(x);
            if (m.count(A - x)) x = A - x;
            else x = B - x;
        }
        
        x = B - v;
        while (m.count(x)) {
            q.push_back({ x,m[x] });
            m.erase(x);
            if (m.count(A - x)) x = A - x;
            else x = B - x;
        }

        if (q.front().first * 2 == A || q.front().first * 2 == B) {
            reverse(q.begin(), q.end());
        }

        for (int i = 0; i < q.size() - 1; i++) {
            ret += min(q[i].second, q[i + 1].second);
            q[i + 1].second -= min(q[i].second, q[i + 1].second);
        }

        if (q.back().first * 2 == A || q.back().first * 2 == B) {
            ret += q.back().second / 2;
        }

    }

    cout << ret;

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