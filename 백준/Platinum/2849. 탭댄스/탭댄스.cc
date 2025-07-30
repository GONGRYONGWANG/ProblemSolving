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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


bool col[200001];

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;
    
    map<int, int> m;
    multiset<int> st;
    for (int i = 1; i <= N; i++) {
        m[i] = i;
        st.insert(1);
    }

    while (Q--) {
        int x; cin >> x;

        if (x != 1) {
            if (col[x] != col[x - 1]) {
                auto it = prev(m.lower_bound(x));
                st.erase(st.find(it->second - it->first + 1));
                m[x] = it->second;
                st.insert(it->second - x + 1);
                it->second = x - 1;
                st.insert(it->second - it->first + 1);
            }
            else {
                auto it = prev(m.lower_bound(x));
                st.erase(st.find(it->second - it->first + 1));
                it->second = m[x];
                st.insert(it->second - it->first + 1);

                st.erase(st.find(m[x] - x + 1));
                m.erase(x);
            }
        }

        if (x != N) {
            if (col[x] != col[x + 1]) {
                auto it = prev(m.upper_bound(x));
                st.erase(st.find(it->second - it->first + 1));

                m[x + 1] = it->second;
                st.insert(it->second - (x + 1) + 1);

                it->second = x;
                st.insert(x - it->first + 1);

            }
            else {
                auto it = prev(m.upper_bound(x));
                st.erase(st.find(it->second - it->first + 1));
                
                it->second = m[x + 1];
                st.insert(it->second - it->first + 1);

                st.erase(st.find(m[x + 1] - (x + 1) + 1));
                m.erase(x + 1);
            }
        }

        col[x] = !col[x];

        cout << *st.rbegin() << endl;

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