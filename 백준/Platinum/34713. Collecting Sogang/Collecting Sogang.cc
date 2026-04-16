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
const long double pi = acosl(-1);
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


void solve(int tc) {
    int N;
    cin >> N;
    set<int> gst;
    queue<int> s, o, g, a, n;
    for (int i = 0; i < N; i++) {
        char x; cin >> x;
        if (x == 's') s.push(i);
        else if (x == 'o') o.push(i);
        else if (x == 'g') {
            g.push(i);
            gst.insert(i);
        }
        else if (x == 'a') a.push(i);
        else if (x == 'n') n.push(i);
    }

    vector<pii> arr;
    while (1) {

        int _g, _n;

        if (s.empty()) break;
        int x = s.front(); s.pop();

        while (!o.empty() && o.front() < x) o.pop();
        if (o.empty()) break;
        x = o.front(); o.pop();

        while (!g.empty() && g.front() < x) g.pop();
        if (g.empty()) break;
        x = g.front(); g.pop(); _g = x;

        while (!a.empty() && a.front() < x) a.pop();
        if (a.empty()) break;
        x = a.front(); a.pop();

        while (!n.empty() && n.front() < x) n.pop();
        if (n.empty()) break;
        x = n.front(); n.pop(); _n = x;

        arr.push_back({ _g,_n });
    }


    int l = 0;
    int r = arr.size();
    while (l < r) {
        int m = (l + r + 1) / 2;
        set<int> st = gst;
         
        for (int j = 0; j < m; j++) st.erase(arr[j].first);

        bool flag = true;
        for (int j = 0; j < m; j++) {
            auto it = st.upper_bound(arr[j].second);
            if (it == st.end()) {
                flag = false;
                break;
            }
            st.erase(it);
        }

        if (flag) l = m;
        else r = m - 1;

    }

    cout << l;



    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}