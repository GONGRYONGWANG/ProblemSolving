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



void solve(int tc) {

    int N;
    cin >> N;
    multiset<int> st;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());

    multiset<int> draw;

    int ans = 0;
    for (int x : arr) {
        auto it = st.upper_bound(x);
        if (it != st.end()) {
            ans += 100;
            st.erase(it);
            continue;
        }
        
        it = draw.upper_bound(x);
        if (it != draw.end()) {
            ans += 30;
            draw.erase(it);
            st.erase(st.begin());
            continue;
        }

        it = st.lower_bound(x);
        if (it != st.end()) {
            draw.insert(x);
            st.erase(it);
            ans += 20;
            continue;
        }

        ans -= 50;
        st.erase(st.begin());

    }

    cout << ans;









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