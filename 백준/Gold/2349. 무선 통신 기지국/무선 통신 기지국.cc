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


pll arr[12];

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        ld x, y;
        cin >> x >> y;
        arr[i] = { x * 100,y * 100 };
    }

    vector<pii> edge;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second) <= 4000000) {
                edge.push_back({ i,j });
            }
        }
    }

    int ret = 5;

    for (int bit = 0; bit < (1 << (2 * (N - 1))); bit++) {
        vector<int> arr(N);
        arr[N - 1] = 0;
        int x = bit;
        for (int i = 0; i < N - 1; i++) {
            arr[i] = x % 4;
            x /= 4;
        }
        bool flag = true;
        for (auto& [u, v] : edge) {
            if (arr[u] == arr[v]) flag = false;
        }

        if (!flag) continue;

        set<int> st;
        for (int i = 0; i < N; i++) {
            st.insert(arr[i]);
        }

        ret = min(ret, int(st.size()));

    }

    cout << ret;


    






    // cout << "Case #" << tc << ": " << ret << endl;
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