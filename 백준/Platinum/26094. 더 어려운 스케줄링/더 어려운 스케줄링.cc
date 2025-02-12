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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    deque<set<int>> q;
    bool dir = false;

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p;
            cin >> p;
            set<int> st;
            st.insert(p);
            if (!dir) q.push_front(st);
            else q.push_back(st);
        }
        else if (t == 1) {
            dir = false;
            if (q.empty()) continue;
            int idx = 0;
            for (int i = 0; i < q.size(); i++) {
                if (q[i].size() > q[idx].size()) idx = i;
            }

            set<int>& st = q[idx];
            for (int i = 0; i < idx; i++) {
                for (auto it = q.front().begin(); it != q.front().end(); it++) st.insert(*it);
                q.pop_front();
            }
            while (q.size() != 1) {
                for (auto it = q.back().begin(); it != q.back().end(); it++) st.insert(*it);
                q.pop_back();
            }
        }
        else if (t == 2) dir = !dir;
        else {
            if (!dir) {
                cout << *q.front().begin();
                q.front().erase(q.front().begin());
                if (q.front().empty()) q.pop_front();
            }
            else {
                cout << *q.back().rbegin();
                q.back().erase(*q.back().rbegin());
                if (q.back().empty()) q.pop_back();
            }
            cout << endl;
        }
    }





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